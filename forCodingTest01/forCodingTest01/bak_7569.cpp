#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int M, N, H;
int arr[101][101][101];
int visited[101][101][101];
int ret = 0;
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 0,0,0,0,1,-1 };
int dh[] = { 1,-1,0,0,0,0 };

queue<pair<int,pair<int,int>>>q;

void init();

int main() {
	init();
	cin >> M >> N >> H;
	for (int k = 0; k< H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int a; cin >> a;
				if (a == 1) {
					q.push({ k,{i,j} });
				}
				if (a == 0) {
					visited[k][i][j] = -1;
				}
				arr[k][i][j] = a;
			}
		}
	}
	
	while (!q.empty()) {
		int cur_h = q.front().first;
		int cur_y = q.front().second.first;
		int cur_x = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nh = cur_h + dh[i];
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (nh < 0 || ny < 0 || nx < 0 || nh >= H || ny >= N || nx >= M)continue;
			if (visited[nh][ny][nx] < 0) {
				visited[nh][ny][nx] = visited[cur_h][cur_y][cur_x] + 1;
				q.push({ nh,{ny,nx} });
			}
		}

	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ret = max(ret, visited[k][i][j]);
				if (visited[k][i][j] == -1) {
					cout << "-1";
					exit(0);
				}
			}
		}
	}
	cout << ret;

	return 0;
}

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}