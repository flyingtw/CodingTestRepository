#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// 바이러스 만났을때 활성화 시키는게 거리가 아니라 시간(초) 이니까
// 활성화된 바이러스부터 0으로 시작할 필요가 없었다!
// 바이러스 끼리 활성화된건 제외해줘야 한다. (2-> 2(활성))

int N,M;
int arr[55][55];
vector<pair<int, int>>v;
vector<pair<int, int>>v2;
bool check[10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[55][55];
bool visited2[55][55];
int ret = 1e9;



void spread() {
	memset(visited, false, sizeof(visited));
	memset(visited2, false, sizeof(visited2));
	queue<pair<int, int>>q;
	

	for (auto it : v2) {
		q.push({ it.first ,it.second });
		visited2[it.first][it.second] = true;
	}
	while (!q.empty()) {
		int level = 1;
		int q_size = (int)q.size();
		while (q_size>0) {
			int cur_y = q.front().first;
			int cur_x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = cur_y + dy[i];
				int nx = cur_x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (arr[ny][nx] == 1) {
					visited[ny][nx] = -1;
					continue;
				}
				//if (arr[ny][nx] == 2 && visited2[ny][nx] == false) {
				//	//visited[ny][nx] = 0;
				//	q.push({ ny,nx });
				//	/visited[ny][nx] = 0;
				//	visited2[ny][nx] = true;
				//	continue;
				//}
				if ((arr[ny][nx] == 0|| arr[ny][nx] == 2) && visited[ny][nx] == 0 && visited2[ny][nx]==false) {
					visited2[ny][nx] = true;
					visited[ny][nx] = visited[cur_y][cur_x]+1;
					q.push({ ny,nx });
				}
			}
			q_size--;
		}
		level++;
		
	}
	/*cout << endl;

	cout << "-------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << visited2[i][j] << " ";
		}
	}
	cout << "----------ㅇ---------" << endl;
	
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
	}
	cout << "-------------------" << endl;*/
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 2) {
				tmp = max(visited[i][j], tmp);
			}
			
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && visited2[i][j] == false){
				tmp = -1;
			}
		}
	}
	if (tmp != -1) {
		ret = min(tmp, ret);
	}
	
	
	
	

}

void virus(int idx) {
	if ((int)v2.size() == M) {
		spread();

		return;
	}
	for (int i = idx; i < (int)v.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			v2.push_back(v[i]);
			virus(i + 1);
			check[i] = false;
			v2.pop_back();
		}
	}
}

int main() {
	init();

	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			if (a == 2) {
				v.push_back({ i,j });
			}
			arr[i][j] = a;
		}
	}
	virus(0);
	if (ret == 1e9) {
		cout << -1;
	}
	else {
		cout << ret;
	}
	
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}