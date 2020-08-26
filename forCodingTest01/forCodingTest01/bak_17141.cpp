#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();
void print();

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M;//M : 바이러스 갯수
char arr[51][51];
int tmp_arr[51][51];
int visited[51][51];
vector<pair<int, int>>v;
int result = 99999999;

void virus() {
	memset(visited, 0, sizeof(visited));
	memset(tmp_arr, 0, sizeof(tmp_arr));
	queue<pair<int, int>>q;
	int ret = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		q.push({ v[i].first,v[i].second });
		visited[v[i].first][v[i].second] = true;
	}
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (arr[ny][nx] != '1' && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				tmp_arr[ny][nx] = tmp_arr[cur_y][cur_x] + 1;
				ret = max(ret, tmp_arr[ny][nx]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp_arr[i][j] == 0 && arr[i][j] == '0') {
				ret = 999999;
				break;
			}
			if (ret == 999999)break;
		}
	}
	result = min(ret, result);
	/*print();
	cout << endl;
	cout << ret << endl;
	cout << "---------------------" << endl;
	cout << endl;*/
	
}

void plant(int n, int idx) {
	if (n == M) {
		virus();
		return;
	}
	for (int i = idx / N; i < N; i++) {
		for (int j = idx % N; j < N; j++) {
			idx++;
			if (arr[i][j] == '2') {
				arr[i][j] = 0;
				//tmp_arr[i][j] = 1;
				v.push_back({ i,j });
				plant(n + 1, idx);
				v.pop_back();
				//tmp_arr[i][j] = 0;
				arr[i][j] = '2';
			}
		}
	}

}

int main() {
	init();
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	plant(0,0);

	//print();
	if (result == 999999)cout << -1;
	else cout << result;
	//cout << "답 :" << result << endl;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << tmp_arr[i][j] << " ";
		}
	}
}