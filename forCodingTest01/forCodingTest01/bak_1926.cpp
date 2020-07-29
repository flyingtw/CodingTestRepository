#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[501][501];
bool visited[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int a1 = 0;
int a2 = 0;

//1이 그림
//1. 그림의 개수
//2. 가장 넓은 그림의 넓이

int dfs(int x, int y,int num) {
	visited[x][y] = true;
	int n_num=num;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>=N || ny>=M)continue;
		if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
			
			
			n_num=dfs(nx, ny,num+1);
			
		}
	}
	return n_num;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				a1++;
				a2 = max(dfs(i, j, 1), a2);	
			}
		}
	}

	cout << a1 << endl;
	cout << a2 << endl;

	return 0;
}