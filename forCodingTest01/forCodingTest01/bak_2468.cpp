#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101][101];
bool visited[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr_tmp[101][101];
int max_h = -1;
int num = 0;

void bfs(int x, int y, int h) {
	visited[x][y] = true;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny<0 || nx > N || ny>N)continue;
			if (arr[nx][ny] > h && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int h; cin >> h;
			max_h = max(h, max_h);
			arr[i][j] = h;
		}
	}
	//2이하 부터 ~ 100 이하 까지 잠김
	for (int i = 0; i <= 101; i++) {
		memset(visited, false, sizeof(visited));
		int tmp = 0;
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				if (arr[a][b] > i && visited[a][b] == false) {
					bfs(a, b,i);
					tmp++;
				}
			}
		}
		num = max(tmp, num);
	}
	cout << num;

	return 0;
}