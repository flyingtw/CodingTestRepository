#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
char arr[101][101];
bool visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int normal_ppl=0;
int color_ppl=0;

//적록색약 : R=G, B
void bfs(int y, int x, char c) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx<0 || ny >= N || nx>N)continue;
			if (arr[ny][nx] == c && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}
void color_bfs(int y, int x, char c) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx<0 || ny >= N || nx>N)continue;
			if (c == 'R' || c == 'G') {
				if ((arr[ny][nx] == 'R' || arr[ny][nx] == 'G') && visited[ny][nx] == false) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
			else {
				if (arr[ny][nx] == c  && visited[ny][nx] == false) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}


int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				char color = arr[i][j];
				bfs(i, j, color);
				normal_ppl++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				char color = arr[i][j];
				color_bfs(i, j, color);
				color_ppl++;
			}
		}
	}
	cout << normal_ppl<<" "<<color_ppl;
	




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}