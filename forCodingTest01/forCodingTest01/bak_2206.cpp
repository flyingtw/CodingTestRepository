#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();
int N, M;
int arr[1001][1001];
int visited[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>>v;
int wall = 0;
int ret;
bool flag = false;



void bfs(int y, int x) {
	int cnt = 1;
	visited[y][x] = cnt;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		
		int cur_y, cur_x;
		tie(cur_y, cur_x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (ny == N - 1 && nx == M - 1) {
				ret = min(ret, visited[cur_y][cur_x]);
				flag = true;
				break;
			}
			if (visited[ny][nx] == 0 && arr[ny][nx] == 0) {
				q.push({ ny,nx });
				visited[ny][nx] = visited[cur_y][cur_x] + 1;
			}
		}
	}
	while (!q.empty())q.pop();

}


int main() {
	init();
	cin >> N >> M;
	ret = 999999;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			int a = s[j]-'0';
			if (a == 1) {
				v.push_back({ i,j });
				wall++;
			}
			arr[i][j] = a;
		}
	}
	
	for (int i = 0; i < wall; i++) {
		arr[v[i].first][v[i].second] = 0;
		memset(visited, 0, sizeof(visited));
		bfs(0, 0);
		arr[v[i].first][v[i].second] = 1;
		
	}
	if (flag == false) {
		cout << -1;
	}
	else {
		cout << ret+1;
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
