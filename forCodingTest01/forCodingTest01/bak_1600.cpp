#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

struct Monkey {
	int y;
	int x;
	int wcnt;
	int time;
};

int K, N, M;
int arr[202][202];
bool visited[202][202][31];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int hy[8] = {-2,-2,-1,-1,1,1,2,2};
int hx[8] = {-1,1,-2,2,-2,2,-1,1};




void bfs() {
	queue<Monkey>q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;
	bool flag = false;
	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_cnt = q.front().wcnt;
		int cur_time = q.front().time;
		q.pop();
		if (cur_y == N - 1 && cur_x == M - 1) {
			cout << cur_time;
			flag = true;
			break;
		}

		if (cur_cnt < K) {
			for (int i = 0; i < 8; i++) {
				int ny = cur_y + hy[i];
				int nx = cur_x + hx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
				if (arr[ny][nx] == 0 && visited[ny][nx][cur_cnt + 1] == false) {
					q.push({ ny,nx,cur_cnt + 1,cur_time + 1 });
					visited[ny][nx][cur_cnt + 1] = true;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 0 && visited[ny][nx][cur_cnt] == false) {
				q.push({ ny,nx,cur_cnt,cur_time + 1 });
				visited[ny][nx][cur_cnt] = true;
			}
		}

	}

	

	if (flag == false) {
		cout << -1;
	}

}

int main() {
	init();
	cin >> K;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	bfs();



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}