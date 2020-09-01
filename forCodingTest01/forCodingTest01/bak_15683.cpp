#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int imsi = 0;

//MAX 값 : int a = 1e9;


struct CCTV {
	int y, x, name;
};

int N, M;
int arr[10][10];
bool visited[10][10];
int cnt = 0;



int cctv_num = 0;
CCTV cctvs[8];

int ret = 1e9;

int dirs[] = { 4,2,4,4,1 };




void copy_arr(int a[10][10], int b[10][10]) {
	// a배열을 b배열로 만들어줌
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}

}

void check(int dir, CCTV cctv) {
	// dir 0 : 동쪽
	// 1 : 남
	// 2 : 서
	// 3 : 북
	dir %= 4;
	int y = cctv.y;
	int x = cctv.x;
	if (dir == 0) {// 동쪽. x만 증가
		for (int j = x+1; j < M; j++) {
			if (arr[y][j] == 6) {
				break;
			}
			arr[y][j] = -1;
		}
	}
	else if (dir == 1) {//남쪽. y 증가
		for (int i = y + 1; i < N; i++) {
			if (arr[i][x] == 6) {
				break;
			}
			arr[i][x] = -1;
		}
	}
	else if (dir == 2) {//서쪽. x 감소
		for (int j = x - 1; j >= 0; j--) {
			if (arr[y][j] == 6) {
				break;
			}
			arr[y][j] = -1;
		}

	}
	else if (dir == 3) {//북쪽. y 감소
		for (int i = y - 1; i >= 0; i--) {
			if (arr[i][x] == 6)break;
			arr[i][x] = -1;
		}
		
	}
}

void DFS(int cctv_idx) {

	// 
	if (cctv_idx == cctv_num) {
		imsi++;

		int safe = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					safe++;
				}
			}
		}
		ret = min(safe, ret);

		/*cout << "---------"<<imsi<<"----------" << endl;
		for (int i = 0; i < N; i++) {
			cout << endl;
			for (int j = 0; j < M; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << safe << endl;
		cout << endl;
		cout << "-------------------" << endl;*/
		return;// 빠져나오기
	}

	int tmp[10][10];
	
	int type = cctvs[cctv_idx].name;
	for (int i = 0; i < dirs[type - 1]; i++) {
		copy_arr(tmp, arr);// tmp 배열에 저장

		
		if (type == 1) {// 한쪽방향만 ->
			check(i, cctvs[cctv_idx]);
		}
		else if (type == 2) { // 기준(->), +180도 (<-)
			check(i, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
		}
		else if (type == 3) {// 기준(->), +90도(v)
			check(i,cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
		}
		else if (type == 4) {// 기준(->), +90도(v), +180도(<-) 
			check(i, cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
		}
		else if (type == 5) {// 모든방향 (->, <-, v, ㅅ)
			check(i, cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
			check(i+3, cctvs[cctv_idx]);
		}

		DFS(cctv_idx + 1);

		// 백트래킹
		copy_arr(arr, tmp);
	}
}




int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i][j] = a;
			if (a != 0 && a!=6) {
				cctvs[cctv_num].y = i;
				cctvs[cctv_num].x = j;
				cctvs[cctv_num].name = arr[i][j];
				cctv_num++;

			}
		}
	}
	DFS(0);
	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}