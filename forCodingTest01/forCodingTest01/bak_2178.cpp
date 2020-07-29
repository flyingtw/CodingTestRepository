#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer=0;


// ����θ� ���Ҷ� : D
// ���� ã��� ��翵�� ��ȸ�Ҷ� D
// �׷����߿� D�� �� �� �ִ°� �ִ�.
// ���߿� DP�� Ǯ�� dfs�� �˾ƾ� �Ѵ�. ������ d�� �˾ƾ��Ѵ�.

// �ִܰŸ� 2���� ����� �ִ�.
// 1. 


int bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<pair<int, int>,int>>q;
	q.push({ {x,y},1 });
	while (!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cur_x == N - 1 && cur_y == M - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx<0 || ny<0 || nx>N || ny>M) continue;
			if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
				q.push({ { nx,ny }, cnt+1 });
				visited[nx][ny] = true;
				
			}
		}
	}
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp[j]-'0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				answer=max(bfs(i, j),answer);
			}
		}
	}
	cout << answer;
	


	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}*/


	return 0;
}