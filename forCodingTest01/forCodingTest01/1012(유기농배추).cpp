#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define endl "\n"

using namespace std;	



int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[50][50] = { false, };
int T;
int N,M;
int n;
//int M;
//vector<int, int>maps;
int maps[50][50] = { 0, };

void BFS(int x, int y) {
	queue<pair<int, int>>Q;
	Q.push(make_pair(x, y));

	visited[x][y] = true;

	while (!Q.empty()) {
		int cur_x = Q.front().first;
		int cur_y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (maps[nx][ny] == 0 || visited[nx][ny] == true) continue;
			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
		}
	}


}






int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<int>result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int bae = 0;

		memset(maps, 0, sizeof(maps));
		memset(visited, false, sizeof(visited));
		cin >> N >> M >> n;
		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			maps[x][y] = 1;
		}
		/*for (int a = 0; a < N; a++) {
			cout << endl;
			for (int b = 0; b < M; b++) {
				cout << maps[a][b] << " ";
			}
		}*/
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (maps[a][b] == 1 && visited[a][b] == false) { 
					BFS(a, b);
					bae += 1;
				}
			}
		}
		cout << bae << endl;
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}