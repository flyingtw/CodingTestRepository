#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int imsi = 0;

//MAX �� : int a = 1e9;


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
	// a�迭�� b�迭�� �������
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}

}

void check(int dir, CCTV cctv) {
	// dir 0 : ����
	// 1 : ��
	// 2 : ��
	// 3 : ��
	dir %= 4;
	int y = cctv.y;
	int x = cctv.x;
	if (dir == 0) {// ����. x�� ����
		for (int j = x+1; j < M; j++) {
			if (arr[y][j] == 6) {
				break;
			}
			arr[y][j] = -1;
		}
	}
	else if (dir == 1) {//����. y ����
		for (int i = y + 1; i < N; i++) {
			if (arr[i][x] == 6) {
				break;
			}
			arr[i][x] = -1;
		}
	}
	else if (dir == 2) {//����. x ����
		for (int j = x - 1; j >= 0; j--) {
			if (arr[y][j] == 6) {
				break;
			}
			arr[y][j] = -1;
		}

	}
	else if (dir == 3) {//����. y ����
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
		return;// ����������
	}

	int tmp[10][10];
	
	int type = cctvs[cctv_idx].name;
	for (int i = 0; i < dirs[type - 1]; i++) {
		copy_arr(tmp, arr);// tmp �迭�� ����

		
		if (type == 1) {// ���ʹ��⸸ ->
			check(i, cctvs[cctv_idx]);
		}
		else if (type == 2) { // ����(->), +180�� (<-)
			check(i, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
		}
		else if (type == 3) {// ����(->), +90��(v)
			check(i,cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
		}
		else if (type == 4) {// ����(->), +90��(v), +180��(<-) 
			check(i, cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
		}
		else if (type == 5) {// ������ (->, <-, v, ��)
			check(i, cctvs[cctv_idx]);
			check(i+1, cctvs[cctv_idx]);
			check(i+2, cctvs[cctv_idx]);
			check(i+3, cctvs[cctv_idx]);
		}

		DFS(cctv_idx + 1);

		// ��Ʈ��ŷ
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