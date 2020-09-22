#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
int y, x, dir;

// 청소기는 바라보는 방향이 있다.
// 동, 서, 남, 북 

// 1. 현재 위치 청소
// 2. 현재에서 방향 기준으로 왼쪽방향으로 차례대로 탐색
//  a. 왼쪽 방향에 청소 안했다면 회전 한 후 한칸 전진 -> 1
//  b. 왼쪽 청소 했다면 -> 그 방향으로 회전 -> 2
//  c. 네 방향 모두 청소 되어있거나 벽
	// -> 방향유지, 한칸 후진
//  d. 4방향 청소 또는 벽, 뒤쪽 벽이라 후진 못하는경우 작동 stop

// -> 로봇 청소기가 청소한 칸은 몇칸인가?

// 0북, 1동, 2남, 3서
// 3서  0북  1동  2남

// 2남  3서  0북  1동

int arr[51][51];
int cnt = 0;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << "----------------" << endl;
}

void clean(int y, int x,int dir) {
	cnt++;

	arr[y][x] = -1;
	//print();

	//cout << "(" << y << ", " << x << ")" << endl;


	// 방향 쪽 갈수 있나?
	// 있다. -> clean(좌표, 방향)
	// 없다. -> 
	int new_dir;
	if (dir == 0)new_dir = 3;
	else new_dir = dir - 1;
	new_dir--;
	for (int i = 0; i < 4; i++) {
		new_dir += 1;
		if (new_dir > 3)new_dir -= 4;
		
		int ny = y + dy[new_dir];
		int nx = x + dx[new_dir];

		if (arr[ny][nx] == 0) {
			clean(ny, nx, new_dir);
			//cout << "2" << endl;
			return;
		}
		//cout << "i :" << i;
		//cout << "3" << endl;

		if (i == 3) {
			//cout << "1" << endl;
			// 모든 방향이 청소가 된 경우 
			
			// 0북, 1동, 2남, 3서
			// 3서  0북  1동  2남
			int origin_dir = dir;

			// 2남  3서  0북  1동
			if (dir < 2) {
				dir += 2;
			}
			else {
				dir -= 2;
			}

			if (arr[y + dy[dir]][x + dx[dir]] != 1 ) {
				//cout << y  << " " << x  << endl;
				//cout << "dir :" << dir << endl;
				//cout << y + dy[dir] << " " << x + dx[dir] << endl;
				clean(y + dy[dir], x + dx[dir], origin_dir);
				return;
			}
			else {
				//cout << "청소 끝!" << endl;
				return;
			}

			
			



		}
	}





	


}


int main() {
	init();
	int ret = 0;
	
	cin >> N >> M;
	cin >> y >> x >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	clean(y, x, dir);
	//cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == -1) {
				ret++;
			}
		}
	}
	//print();
	/*if (ret == 1) {
		cout << 1;
	}
	else {
		cout<<ret+1;
	}*/
	cout << ret << endl;
	//print();

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}