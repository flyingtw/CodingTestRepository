#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

//void print();

int N;
int arr[101][101];
bool visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ret = 99999;
int num = 2;


void div_bfs(int y, int x) {
	arr[y][x] = num;
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y, cur_x;
		tie(cur_y, cur_x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (arr[ny][nx] != 0 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
				arr[ny][nx] = num;
			}
		}
	}
	
}

void bridge_bfs(int n) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == n) {
				q.push({ {i,j},0 });
			}
		}
	}
	while (!q.empty()) {
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (arr[ny][nx] != 0 && arr[ny][nx] != n) {
				ret = min(cnt, ret);
			}
			if (arr[ny][nx] == 0 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push({{ ny,nx }, cnt + 1});
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
	// 1. 각 섬 구분하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				div_bfs(i, j);
				num++;
			}
		}
	}
	//print();

	// 2. 각 섬마다 다른섬끼리 최소 거리 구하기
	for (int i = 2; i <= num; i++) {
		bridge_bfs(i);
	}
	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

//void print() {
//	cout << "--------------------" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << endl;
//		for (int j = 0; j < N; j++) {
//			cout << arr[i][j] << " ";
//		}
//	}
//	cout << endl;
//	cout << "--------------------" << endl;
//}

