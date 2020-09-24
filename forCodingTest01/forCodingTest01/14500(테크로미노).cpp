#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
int arr[501][501];
bool visited[501][501];

// 이어져있는 4개의 연결 모두 구한 후 그 값중 최대값 구하기


void bfs(int y, int x) {

}

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bfs(i, j);
		}
	}
	




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}