#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// 1. 확산 (4방향 -> arr/5, 남은거 -> arr-(arr/5)*확산갯수)
// 2. 공기 청정기
// 위는 반시계, 아래는 시계

int N, M, T;
int arr[51][51];


int main() {
	init();
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}



	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}