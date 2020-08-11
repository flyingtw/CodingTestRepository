#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
char arr[1501][1501];
bool visited[1501][1501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>>swan_loca;
int day = 0;

bool swan_check(int y,int x) {
	bool meet = false;
	memset(visited, false, sizeof(visited));
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
			if ( ny!=y && nx!= x && arr[ny][nx] == 'L') {
				meet = true;
				return meet;
			}
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (visited[ny][nx] == false && arr[ny][nx] == '.') {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
	return meet;
}
void melt(int y, int x) {
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
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;

			if (visited[ny][nx] == false && arr[ny][nx] == '.') {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
			if (arr[ny][nx] == 'X' && visited[ny][nx] == false) {
				arr[ny][nx] = '.';
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
			if (c == 'L') {
				swan_loca.push_back({ i,j });
			}
			arr[i][j] = c;

		}
	}

	bool flag = false;	
	
	while (1) {
		// 1. swan check
		flag = swan_check(swan_loca[0].first, swan_loca[0].second);
		if (flag == true) {
			cout << day;
			break;
		}
		else {
			day++;
		}
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == '.' && visited[i][j] == false) {
					melt(i, j);
				}
			}
		}
	}
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
