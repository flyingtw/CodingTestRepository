#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
char arr[51][51];
int ppl_y, ppl_x;
int exit_y, exit_x;
int x_cnt = 0;
// 모든 X를 지나는 최단경로
// S로 부터 E 까지 갈때 가장 가까운 X1 저장
// X1로부터 E 까지 갈때 가장 가까운 X2 저장
// ....Xn 으로부터 E 까지 갈때 가장 가까운 경로 저장
// 각 x 를 만날때마다 초기화(왔던길 또 갈 수 있으니까)


int main() {
	init();
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			if (c == 'S') {
				ppl_y = i;
				ppl_x = j;
			}
			if (c == 'E') {
				exit_y = i;
				exit_x = j;
			}
			if (c == 'X') {
				x_cnt++;
			}
			arr[i][j] = c;
		}
	}


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}