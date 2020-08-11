#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
char arr[1501][1501];
bool visited[1501][1501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool meet = false;
vector<pair<int, int>>swan_loca;
queue<pair<int, int>>swan;
queue<pair<int, int>>swan_melt;
queue<pair<int, int>>water;
queue<pair<int, int>>water_melt;
int day = 0;

void swan_bfs() {
	while (!swan.empty() && meet==false) {
		int cur_y, cur_x;
		tie(cur_y, cur_x) = swan.front();
		swan.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;

			if (arr[ny][nx] == 'L' && visited[ny][nx]==false) {
				visited[ny][nx] = true;
				meet = true;
				break;
			}
			
			if (arr[ny][nx] == '.' && visited[ny][nx] == false) {
				swan.push({ ny,nx });
				visited[ny][nx] = true;
			}
			if (arr[ny][nx] == 'X' && visited[ny][nx] == false) {
				arr[ny][nx] = '.';
				visited[ny][nx] = true;
				swan_melt.push({ ny,nx });
			}
		}
	}
}
void water_bfs() {
	while (!water.empty()) {
		int y, x;
		tie(y, x) = water.front();
		water.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 'X') {
				arr[ny][nx] = '.';
				water_melt.push({ ny,nx });
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
			if (c == 'L') {
				swan_loca.push_back({ i,j });
			}
			if (c != 'X' ){// L도 물이다!
				water.push({ i,j });
			}
			arr[i][j] = c;
		}
	}
	// swan q 에 첫 좌표 넣어줘야함
	swan.push({ swan_loca[0].first,swan_loca[0].second });
	visited[swan_loca[0].first][swan_loca[0].second] = true;
	while (1) {
		// 1. 백조1 로부터 BFS - swan q 에 첫 좌표 넣어줘야함
		// - X인(녹을) 좌표 swan_q에 저장
		// - 녹이다가 'L'을 만나면 meet=true break;
		swan_bfs();
		if (meet == true)break;
		day++;

		// 2. 물만 녹음
		// - X인(녹을) 좌표 water_q에 저장
		water_bfs();
		swan = swan_melt;
		water = water_melt;
		while (!swan_melt.empty())swan_melt.pop();
		while (!water_melt.empty())water_melt.pop();
	}
	cout << day;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
