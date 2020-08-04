#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N, M;
int arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int time_cnt = 0;
int cheeze = 0;
int answer = 0;



int bfs(int y, int x,int num) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || ny >= N || nx >= M)continue;
			if (arr[ny][nx] == 0 && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
			else if (arr[ny][nx] == 1 && visited[ny][nx] == false) {
				arr[ny][nx] = 0;
				visited[ny][nx] = true;
				cheeze--;
			}
		}
	}
	if (cheeze == 0) {
		return num;
	}
	return cheeze;
	
}
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

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			if (a == 1) {
				cheeze++;
			}
			arr[i][j] = a;
		}
	}
	while (cheeze!=0) {
		memset(visited, 0, sizeof(visited));
		answer=bfs(0, 0,cheeze);
		time_cnt++;
		
	}
	
	cout << time_cnt << endl;
	cout << answer << endl;
	





	return 0;
}