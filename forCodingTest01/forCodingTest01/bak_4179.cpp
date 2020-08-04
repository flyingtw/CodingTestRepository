#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, M;
char arr[1001][1001];
bool fire = false;
int f_x, f_y;
int j_x, j_y;
bool visited[1001][1001];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool jihoon = false;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}
}
bool fire_check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '.')cnt++;
		}
	}
	if (cnt != 0) {
		return true;
	}
	else return false;
}
void bfs_fire(int y, int x) {
	queue<pair<int, int>>fq;
	fq.push({ y,x });
	visited[y][x] = true;
	while (!fq.empty()) {
		int cur_y = fq.front().first;
		int cur_x = fq.front().second;
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == '.' && visited[ny][nx] == false) {
				fq.push({ ny,nx });
				visited[ny][nx] = true;
				arr[ny][nx] = 'F';
			}
		}
	}
}
void bfs_jihoon(int y, int x) {

	queue<pair<int, int>>jq;
	jq.push({ y,x });
	visited[y][x] = true;
	while (!jq.empty()) {
		int cur_y = jq.front().first;
		int cur_x = jq.front().second;
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				jihoon = true;
				break;
			}
			if (arr[ny][nx] == '.' && visited[ny][nx] == false) {
				jq.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}




int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			if (c == 'F') {
				
				f_y = i;
				f_x = j;
			}
			if (c == 'J') {
				j_y = i;
				j_x = j;
			}
			arr[i][j] = c;
		}
	}
	while (fire_check()) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 'F') {
					bfs_fire(f_y, f_x);
				}
			}
		}
		bfs_jihoon(j_y, j_x);
		
	}



	return 0;
}
