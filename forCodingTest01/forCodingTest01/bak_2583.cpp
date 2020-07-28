#include <bits/stdc++.h>

using namespace std;


int M, N, K;
int arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int>v1;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	visited[x][y] = true;
	q.push({ x,y });

	int cnt = 1;
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (arr[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				cnt += 1;
				q.push({ nx,ny });
			}
		}
	}
	v1.push_back(cnt);
}

int main() {
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int a = x1; a < x2; a++) {
			for (int b = y1; b < y2; b++) {
				arr[a][b] = 1;
			}
		}

	}

	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && visited[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	sort(v1.begin(), v1.end());
	int all_cnt = v1.size();
	cout << all_cnt << "\n";
	for (int i = 0; i < all_cnt; i++) {
		cout << v1[i] << " ";
	}
	return 0;
}