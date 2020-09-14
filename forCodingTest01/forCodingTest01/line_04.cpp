#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;

int arr[301][301];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1, 0 };

vector<vector<int>> maze = { {0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, {1, 0, 1, 0} };

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	int level = 0;
	while (!q.empty()) {

		int q_size = (int)q.size();
		while (q_size--) {
			int cur_y, cur_x;
			tie(cur_y, cur_x) = q.front();
			q.pop();
		
			int tmp;
			int i = 0;
			if (i == 0)tmp = 3;
			else { tmp = i - 1; }

			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny == N - 1 && nx == N - 1) {
				cout << level;
				return;
			}

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (arr[ny][nx] == 0 ) {//&& arr[cur_y + dy[tmp]][cur_x + dx[tmp]] == 1
				q.push({ ny,nx });
				cout << ny<<" "<<nx << endl;
			}
			else {
				q.push({ cur_y,cur_x });
				i++;
			}
			
		}
		level++;
		//방향 기준 왼쪽이 벽이면 진행
	}
}



int solution(vector<vector<int>> maze) {
	int answer = 0;
	N = (int)maze.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = maze[i][j];
		}
	}


	/*for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
	}*/

	bfs(0, 0);


	return answer;
}



int main() {
	init();
	solution(maze);


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}