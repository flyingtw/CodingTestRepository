#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// visited[y][x][b]���� �Ÿ���
// visited[y][x][1]�� �νǼ� �ִ� ���� (�νø� ������ ������)
// visited[y][x][0]�� �νǼ� ���� ����

int N, M;

int arr[1001][1001];
int visited[1001][1001][2];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ret = 1e9;

struct str {
	int y;
	int x;
	int b;
};

int bfs(int y, int x) {
	queue<str>q;
	q.push({ y,x,1 });
	visited[y][x][1] = 1;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cb = q.front().b;
		q.pop();

		if (cy == N - 1 && cx == M - 1)return visited[cy][cx][cb];

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			
			// ���� �����µ� Ƚ�� ��������
			if (arr[ny][nx] == 1 && cb == 1) {
				visited[ny][nx][cb - 1] = visited[cy][cx][cb] + 1;
				q.push({ ny, nx, cb - 1 });
				//-> visited[y][x][1](�νô¿��� ����)
				//������ �Ÿ� �ִٰ�
				// �� ������ visited[y][x][0]�� �Ÿ� �ִ´�
			}
			
			// ���� �ƴѵ� �湮 ����
			if (arr[ny][nx] == 0 && visited[ny][nx][cb] == 0) {
				visited[ny][nx][cb] = visited[cy][cx][cb] + 1;
				q.push({ ny,nx,cb });
			}
		}
	}
	return -1;
}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j]-'0';
		}
	}
	cout << bfs(0, 0);
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}