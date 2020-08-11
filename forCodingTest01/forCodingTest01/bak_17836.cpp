#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M, T;
int arr[101][101];
bool visited[101][101];
int dist[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ret;

// Į�� �ݰ� visited �ߴ� ���� ���ư��� �ּҰ��� ������ ���
// Į�� �ݰ� ���� ���� �� ���±溸�� �� �հ��


int bfs(int y, int x) {
	int shortcut = 1000000;

	visited[y][x] = true;
	bool flag = false;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		//bool flag = false;
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			
			if (nx < 0 || ny < 0 || ny >= N || nx >= M)continue;
			if (ny == M - 1 && nx == N - 1) {
				cout << "�� ã���� �ִܰŸ� : " << shortcut << endl;
				cout << "�� ��ã�� �ִܰŸ� :" << dist[cur_y][cur_x] << endl;
				return min(shortcut, dist[cur_y][cur_x]);
			}
			if (arr[ny][nx] == 2) {
				flag = true;
				cout << "2���� �Ÿ� : " << dist[cur_y][cur_x]+1 << endl;
				shortcut = dist[cur_y][cur_x]+N + M - ny - nx - 1;
			}
			
			
			if (flag == false) {
				if (visited[ny][nx] == false && arr[ny][nx] == 0) {
					q.push({ ny,nx });
					dist[ny][nx] = dist[cur_y][cur_x] + 1;
					visited[ny][nx] = true;
				}
			}
			else {
				if (visited[ny][nx] == false) {
					q.push({ ny,nx });
					dist[ny][nx] = dist[cur_y][cur_x] + 1;
					visited[ny][nx] = true;
				}
			}
		}
	}
	return -1;
}



int main() {
	init();
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	
	
	ret=bfs(0, 0);
	if (ret == -1 || ret>T) {
		cout << "Fail";
	}
	else {
		cout << ret+1;
	}
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout<< dist[i][j]<<" ";
		}
	}
	

	
	
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}