#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int a, b, c, d;


bool visited[1000][1000];
map<pair<int, int>, int>m;
queue<pair<int, int>>q;
int ret = 0;
bool flag = false;


void fc1(int y, int x,int cnt) {//y는 비우고 x는 그대로
	y = 0;
	x = x;
	if (y > a || x > b)return;
	if (visited[y][x] == true)return;
	if (y == c && x == d) {
		ret = cnt;
		flag = true;
		return;
	}
	if (visited[y][x] == false) {
		visited[y][x] = true;
		q.push({ y,x });
	}
}
void fc2(int y, int x, int cnt) {
	y = y;
	x = 0;
	if (y > a || x > b)return;
	if (visited[y][x] == true)return;
	if (y == c && x == d) {
		ret = cnt;
		return;
	}
	if (visited[y][x] == false) {
		visited[y][x] = true;
		q.push({ y,x });
	}

}
void fc3(int y, int x, int cnt) {// a -> b
	int ny = y - (b - x);
	if (ny < 0)ny = 0;
	int nx = b - x + y;
	if (nx > b)nx = b;

	if (ny > a || nx > b)return;
	if (visited[ny][nx] == true)return;
	if (ny == c && nx == d) {
		ret = cnt;
		return;
	}
	if (visited[ny][nx] == false) {
		visited[ny][nx] = true;
		q.push({ ny,nx });
	}

}
void fc4(int y, int x, int cnt) {
	int nx = x - (a - y);
	if (nx < 0)nx = 0;
	int ny = a - y + x;
	if (ny > a)ny = a;

	if (ny > a || nx > b)return;
	if (visited[ny][nx] == true)return;
	if (ny == c && nx == d) {
		ret = cnt;
		return;
	}
	if (visited[ny][nx] == false) {
		visited[ny][nx] = true;
		q.push({ ny,nx });
	}

}

int main() {
	init();
	int cnt = 1;
	// c: a 남길물// d: b 남길물// 불가능 : -1
	cin >> a >> b >> c >> d;

	// 1. a = 0 , b = b
	// 2. a = a , b = 0
	// 3. a -> b
	// 4. b -> a
	
	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		
		//4가지 경우
		fc1(y, x, cnt);
		fc2(y, x, cnt);
		fc3(y, x, cnt);
		fc4(y, x, cnt);
		cnt++;
		if (flag == true) {
			break;
		}
		
	}
	if (flag == true) {
		cout << ret;
	}
	else {
		cout << -1;
	}





	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}