#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101][101];
int tmp[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool flag = false;

void bfs_cheese(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>>q2;
	q2.push({ x, y });
	while (!q2.empty()) {
		int cur_x = q2.front().first;
		int cur_y = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (arr[nx][ny] == 0 && visited[nx][ny] == false) {
				tmp[nx][ny] = 2;
				visited[nx][ny] = true;
				q2.push({ nx,ny });
			}
		}
	}
}


void bfs_check_hall(int x, int y) {
	visited[x][y] = true;
	tmp[x][y] = 2;
	queue<pair<int,int>>q;
	q.push({ x, y });
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (arr[nx][ny] == 0 && visited[nx][ny] == false) {
				tmp[nx][ny] = 2;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}


}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && visited[i][j] == false) {
				if (flag == false) { 
					bfs_check_hall(i, j); 
					flag = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] != 2 && arr[i][j] == 0) {
				tmp[i][j] = 3;
			}
		}
	}
	/*cout << "-----------" << endl;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << tmp[i][j] << " ";
		}
	}*/
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 1 && visited[i][j] == false) {
				bfs_cheese(i, j);
			}
		}
	}




	return 0;
}