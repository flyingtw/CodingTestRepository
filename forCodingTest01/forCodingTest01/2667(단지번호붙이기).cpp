#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"

using namespace std;


// BFS�� ��ǥ(x, y)�� �Ѱ��ָ� �� ���� �߰��Ҷ����� cnt�� ++ ���ְ�
// ���ο� ���� ���ð�쿣 cnt = 1 �� �ʱ�ȭ���ش�


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[25][25] = { false, };
int N;
//int M;
//vector<int, int>maps;
int maps[25][25] = { 0, };
queue<pair<int, int>>Q;

int BFS(int x, int y) {
	Q.push(make_pair(x, y));


	int cnt = 1;
	visited[x][y] = true;
	
	while (!Q.empty()) {
		int cur_x = Q.front().first;
		int cur_y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (maps[nx][ny]==0 || visited[nx][ny] == true) continue;
			visited[nx][ny] = true;
			Q.push(make_pair(nx, ny));
			cnt++;//���� ���ֱ�
		}
	}
	return cnt;
	
}






int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int>result;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < N; j++) {
			maps[i][j] = (int)a[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 1 && visited[i][j] == false) {
				result.push_back(BFS(i, j));
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}


	return 0;
}