#include <bits/stdc++.h>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool visited[60][60];
int arr[60][60];


int T;
int M, N, K;


void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		//tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x +dx[i];
			int ny = cur_y +dy[i];
			if (nx<0 || ny <0 || nx>=M || ny >=N)continue;
			if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		
	}
	

}



int main() {

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int num = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x, y; cin >> x >> y;
			arr[x][y] = 1;
		}
		
		
		for (int a = 0; a < M; a++) {
			for (int b = 0; b < N; b++) {
				
				if (arr[a][b] == 1 && visited[a][b]==false) {
					
					bfs(a, b);
					num+=1;
					
					

				}
				

			}
		}
		cout << num << endl;
		
	}




	return 0;
}