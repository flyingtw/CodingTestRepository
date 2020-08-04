#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int M, N, H;
int arr[101][101][101];
bool visited[101][101][101];
int cnt = 0;
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 0,0,0,0,1,-1 };
int dh[] = { 1,-1,0,0,0,0 };
int changed = 0;

int imsi = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}




int bfs(int h, int x, int y) {
	int ab = 0;
	visited[h][x][y] = true;
	queue<pair<int,pair<int, int>>>q;

	q.push({ h,{x,y} });
	
	while (!q.empty()) {
		int cur_h = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		cout << "현재 : "<<cur_h << " " << cur_x << " " << cur_y << endl;
		
		/*int cur_h = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;*/
		q.pop();
		
		
		for (int i = 0; i < 6; i++) {
			int nh = cur_h + dh[i];
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nh < 0 || nx < 0 || ny < 0 || nh >= H || nx >= N || ny >= M)continue;
			if (arr[nh][nx][nh] == 0 && visited[nh][nx][ny] == false) {
				cout << "나중 : " << nh << " " << nx<< " " << ny<< endl;
				q.push({ nh,{nx,ny} });
				visited[nh][nx][ny] = true;
				arr[nh][nx][ny] = 1;
				ab +=1;
			}
		}
	}

	return ab;
}

bool check() {
	bool flag = true;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[k][i][j] == 0) {
					flag = false;
					break;
				}
			}
			if (flag == false) break;
		}
		if (flag == false) break;
	}
	return flag;
}

int main() {
	init();
	cin >> M >> N >> H;
	for (int k = 0; k< H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int a; cin >> a;
				arr[k][i][j] = a;
			}
		}
	}
	
	/*memset(visited, 0, sizeof(visited));
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[k][i][j] == 1 && visited[k][i][j] == false) {
					changed=bfs(k, i, j);
				}
			}
		}
	}*/
	
	for (int k = 0; k < H; k++) {
		cout << endl;
		for (int i = 0; i < N; i++) {
			cout << endl;
			for (int j = 0; j < M; j++) {
				cout << arr[k][i][j] << " ";
			}
		}
	}

	
	
	
	return 0;
}
