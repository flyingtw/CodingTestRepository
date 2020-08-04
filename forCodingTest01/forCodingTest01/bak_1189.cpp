#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int visited[6][6];
char arr[6][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;

void dfs(int y, int x,int cnt) {
	if (y == R-1 && x == C-1 && cnt==K) {
		answer++;
		return;

	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i],nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (arr[ny][nx] == '.' && visited[ny][nx] == false) {
			visited[ny][nx] = true;
			dfs(ny, nx,cnt+1);
			visited[ny][nx] = false;
		}
	}
}


int main() {

	cin >> R >> C >> K;
	for (int i = R-1; i >=0; i--) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}
	//print();
	/*for (int i = R-1; i >= 0; i--) {
		for (int j = 0; j <C; j++) {
			if (arr[i][j] == '.' && !visited[i][j]) {
				dfs(i, j);
			}
		}
	}*/
	visited[0][0] = true;
	dfs(0, 0,1);
	cout << answer;
	


	return 0;
}