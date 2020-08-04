#include <bits/stdc++.h>
#define endl "\n"
using namespace std;



int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, M;
char arr[301][301];
bool visited[301][301];
int x_1, y_1, x_2, y_2;
bool suspect = false;
int cnt = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void bfs(int y, int x) {
	cnt++;
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		//cout << cur_y << " " << cur_x << endl;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] == '0' && visited[ny][nx] == false) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
			else if(arr[ny][nx] == '1' && visited[ny][nx] == false) {
				arr[ny][nx] = '0';
				visited[ny][nx] = true;
			}
			else {
				if (arr[ny][nx] == '#') {
					suspect = true;
					break;
				}
			
			}
		}
	}

}
void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout<<arr[i][j]<<" ";
		}
	}
}

int main() {
	init();
	
	cin >> N >> M;
	cin>>x_1 >> y_1 >> x_2 >> y_2;
	x_1 -= 1;
	y_1 -= 1;
	x_2 -= 1;
	y_2 -= 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}
	while (!suspect) {
		memset(visited, 0, sizeof(visited));
		bfs(x_1, y_1);
		//print();
	}
	cout << cnt;



	return 0;
}
