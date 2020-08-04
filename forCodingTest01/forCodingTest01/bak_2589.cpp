#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, M;
char arr[51][51];
int visited[51][51];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int num = 0;
int ret = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>>q;
	q.push({ y,x });
	num = 0;
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i ++ ) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			//cout << "visited :" << visited[ny][nx] << endl;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M )continue;
			if (arr[ny][nx] == 'L' && visited[ny][nx] == 0) {
				visited[ny][nx] = visited[cur_y][cur_x] + 1;
				q.push({ ny,nx });
				if (num <= visited[ny][nx]) {
					num = visited[ny][nx];
				}
			}


		}


	}
	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
	}
	cout << "--------------------" << endl;*/


}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, 0, sizeof(visited));
			if (arr[i][j] == 'L' && visited[i][j] == false) {
				bfs(i, j);
				ret = max(num, ret);
			}
		}
	}
	
	
	

	
	cout << ret-1;

	return 0;
}
