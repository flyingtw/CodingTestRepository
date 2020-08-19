#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


int N, K;
bool visited[500000];
int cnt = 1;

int da[3] = { 1,-1,0 };
int db[3] = { 1,1,2 };

vector<int>even;
vector<int>odd;

bool findodd(int n) {
	bool flag = false;
	for (int i = 0; i < odd.size(); i++) {
		if (odd[i] == n) {
			flag = true;
			return flag;
		}
	}
	return flag;
}
bool findeven(int n) {
	bool flag = false;
	for (int i = 0; i < even.size(); i++) {
		if (even[i] == n) {
			flag = true;
			return flag;
		}
	}
	return flag;
}


int bfs(int x) {
	visited[N - 1] = true;
	queue<int>q;
	q.push( x );
	
	while (!q.empty()) {
		
		
		int cur_x = q.front();
		q.pop();
		
		K = K + cnt;
		
		cout << "K : " << K << endl;
		cout << "cnt : " << cnt << endl;

		for (int i = 0; i < 3; i++) {
			int nx = (db[i] * cur_x) + da[i];
			cout << nx;
			if (nx == K)return cnt;
			if (cnt % 2 == 1) {
				if (findodd(nx) == true) {
					return cnt;
				}
			}
			else {
				if (findeven(nx) == true) {
					return cnt;
				}
			}
			if (nx < 0 || nx >= 500000)continue;
			if (visited[nx] == true)continue;
			if (visited[nx] == false) {
				q.push(nx);
				if (cnt % 2 == 1) {
					odd.push_back(nx);
				}
				else {
					even.push_back(nx);
				}
			}
		
		}
		
	}
	
	return -1;
}


int main() {
	init();
	cin >> N >> K;
	
	cout<<bfs(N);


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}