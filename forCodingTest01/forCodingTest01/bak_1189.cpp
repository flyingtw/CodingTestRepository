#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int visited[6][6];
char arr[6][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>>q;
	q.push({ x,y });
	int cnt = 1;
	
	while (!q.empty()) {
		int cur_x, cur_y;
		tie(cur_x, cur_y) = q.front();
		q.pop();
		//int cur_x = q.front().first;
		
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (arr[nx][ny] == '.' && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt += 1;
			}
		}
	}
	cout << cnt;

}

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}
	for (int i = R-1; i >= 0; i--) {
		for (int j = 0; j <C; j++) {
			if (arr[i][j] == '.' && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	


	return 0;
}