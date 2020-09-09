#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
int arr[501][501];
bool visited[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ret_img_cnt = 0;
int ret_img_space = 0;

// 첫째 : 그림의 갯수
// 둘째 : 가장 넓은 그림의 넓이

void bfs(int y, int x) {
	ret_img_cnt++;
	int cnt = 1;
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + cur_y;
			int nx = dx[i] + cur_x;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				cnt++;
				q.push({ ny,nx });
			}
		}
	}

	ret_img_space = max(ret_img_space, cnt);


}


int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
			}
		}
	}
	cout << ret_img_cnt << endl;
	cout << ret_img_space;



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}