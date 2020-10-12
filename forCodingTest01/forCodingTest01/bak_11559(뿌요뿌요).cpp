#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

char arr[12][6];
bool visited[12][6];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<pair<int, int>>v;

int ret = 0;


void print();

void dfs(int y, int x, char c) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6)continue;
		if (visited[ny][nx] == false && arr[ny][nx] == c) {
			v.push_back({ ny,nx });
			dfs(ny, nx, c);
		}
	}
}


// R G B P Y 5가지 색깔
int main() {
	init();
	for (int i = 0; i < 12; i++) {
		string s; cin >> s;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = s[j];
		}
	}
	//print();
	//cout << "---" << endl;

	

	while (true) {
		bool flag = false;
		memset(visited, false, sizeof(visited));
		
		//내리기
		queue<char>q;
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				if (arr[i][j] != '.') {
					q.push(arr[i][j]);
					arr[i][j] = '.';
				}
			}

			int imsi_y = 11;
			while (!q.empty()) {
				char c1 = q.front(); q.pop();
				if (arr[imsi_y][j] == '.') {
					arr[imsi_y][j] = c1;
				}
				imsi_y--;
			}



		}
		//print();
		//cout << "---" << endl;



		// 터트리기
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] == false && arr[i][j] != '.') {
					v.push_back({ i,j });
					dfs(i, j, arr[i][j]);
					if ((int)v.size() >= 4) {
						for (auto it : v) {
							arr[it.first][it.second] = '.';
							flag = true;
						}
					}
					v.clear();
				}
			}
		}
		//print();
		//cout << "----" << endl;
		
		if (flag == false)break;
		ret++;
	}
	print();
	cout << ret << endl;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}