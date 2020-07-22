#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
bool bfs_visited[10][10];
bool c_check[10][10];
int arr[10][10];
queue <pair<int, int>>q;
int safe;
int maxSafe = 0;


void bfs(int y, int x) {
	bfs_visited[y][x] = true;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (nx < 0 || ny < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == 0 && bfs_visited[ny][nx] == false) {
				bfs_visited[ny][nx] = true;
				arr[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}
	safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				safe++;
			}
		}
	}
	maxSafe = max(safe, maxSafe);
}

void virus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 && bfs_visited[i][j] == false) {
				bfs_visited[i][j] = true;
				bfs(i, j);

			}
		}
	}

}




void check(int num) {
	if (num == 3) {
		memset(bfs_visited, false, sizeof(bfs_visited));
		virus();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]==0) {
				arr[i][j] = 1;
				check(num + 1);
				arr[i][j] = 0;
			}
		}
	}
}



int main() {
	cin >> n >> m;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	
	check(0);
	
	cout << maxSafe << endl;

	return 0;
}