#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
int arr[55][55];
int visited[55][55];
int dy[4] = { 0,-1,0,1 }, dx[4] = { -1,0,1,0 };
bitset<4>bb;
int num=1;
vector<int>v;

bool visited2[55][55];
vector<int>v2;

int ret1, ret2, ret3;


void bfs2(int y, int x) {
	visited2[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (visited[ny][nx] != visited[cur_y][cur_x]) {
				v2[visited[cur_y][cur_x]-1]=max(v2[visited[cur_y][cur_x]-1], v[visited[ny][nx]-1]+v[visited[cur_y][cur_x] - 1]);
			}
			if ((visited[ny][nx] == visited[cur_y][cur_x]) && visited2[ny][nx]==false) {
				q.push({ ny,nx });
				visited2[ny][nx] = true;
			}
		}
	}
}

bool check(int cur_y,int cur_x,int ny,int nx,int dir) {
	int n_p = arr[cur_y][cur_x];
	// 현재 정점과 1,2,4,8 과 & 연산해서 1이면 벽
	if (dir == 0) {//<-
		if ((n_p & 1) == 1)return true;
	}
	else if (dir == 1) {// ^
		if ((n_p & 2) ==2)return true;
	}
	else if (dir == 2) {// ->
		if ((n_p & 4) ==4)return true;
	}
	else if (dir == 3) {// v
		if ((n_p & 8) ==8) return true;
	}
	return false;
}

void bfs(int y, int x) {
	int room_size = 1;
	visited[y][x] = num;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (check(cur_y, cur_x, ny, nx, i) == true)continue;// 벽이므로 continue
			if (visited[ny][nx] == 0) {
				q.push({ ny,nx });
				visited[ny][nx] = num;
				room_size++;
			}
		}
	}
	v.push_back(room_size);
	num++;
}




int main() {
	init();
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	// bfs 돌리는데,
	// 다음점 갈때 상하좌우가 아닌 2진법 벽 유무로 판단.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
	}*/

	/*for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " ";
	}*/




	// 각점마다의 최대 확장 크기 구하기
	for (int i = 0; i < (int)v.size(); i++) {
		v2.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited2[i][j] == false) {
				bfs2(i, j);
			}
		}
	}
	ret1 = (int)v.size();
	ret2= *max_element(v.begin(), v.end());
	ret3= *max_element(v2.begin(), v2.end());
	cout << ret1 << endl;
	cout << ret2 << endl;
	cout << ret3 << endl;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}