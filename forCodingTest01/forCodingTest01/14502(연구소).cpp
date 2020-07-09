#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"


using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;
int M;
//vector<int, int>maps;
int maps[8][8] = { 0, };

int maxSafe = 0;
queue<pair<int, int>>q;


// 연구실 바이러스 문제
// 1. 벽 3개를 세울 수 있는 모든 경우를 구한다.(브루트 포스)
// 2. 각 경우마다 BFS를 구해준다.
// 3. 모든 경우의 최댓값을 구한다.


void virus() {
	int safe = 0;
	int vMaps[8][8] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vMaps[i][j] = maps[i][j];
		}
	}
	bool visited[8][8] = { false, };
	queue<pair<int, int>>Q = q;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		visited[x][y] = true;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (vMaps[nx][ny] == 0 ) {
					vMaps[nx][ny] = 2;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vMaps[i][j] == 0) {
				safe+=1;
			}
		}
	}
	maxSafe = max(safe, maxSafe);
}


void wall(int wallN) {
	if (wallN==3) {
		virus();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0) {
				maps[i][j] = 1;
				wall(wallN+1);
				maps[i][j] = 0;//되돌려주기
			}
		}
	}

}




int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >>maps[i][j];
			if (maps[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	wall(0);
	cout << maxSafe << endl;


	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << maps[i][j] << " ";
		}
	}*/
	//cout << solution(maps) << endl;

	return 0;
}