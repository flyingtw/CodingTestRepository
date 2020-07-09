#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"


using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[100][100] = { false, };
int N;
int M;
//vector<int, int>maps;
int maps[100][100] = { 0, };


int solution(int maps[100][100]) {
	queue < pair<pair<int, int>, int>>Q;
	Q.push(make_pair(make_pair(0, 0), 1));
	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int cnt = Q.front().second;
		Q.pop();

		if (x == N - 1 && y == M - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (maps[nx][ny] == 1 && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					Q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
	return -1;




}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M; j++) {
			maps[i][j] = (int)a[j] - '0';
		}
	}
	/*for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << maps[i][j] << " ";
		}
	}*/
	cout<<solution(maps)<<endl;

	return 0;
}