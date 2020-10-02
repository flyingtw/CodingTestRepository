#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();



int N, M, K;

bool notebook[41][41];

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << notebook[i][j] << " ";
		}
		cout << endl;
	}
}



struct Stick {
	int y, x;
	int arr[10][10];
};

Stick st[100];

void real_draw(int st_num, int y, int x) {
	int st_y = st[st_num].y;
	int st_x = st[st_num].x;
	for (int b = y; b < st_y + y; b++) {
		for (int a = x; a < st_x + x; a++) {
			if (st[st_num].arr[b][a] == 1) {
				notebook[b][a] = st[st_num].arr[b - y][a - x];
			}
		}
	}
}


bool check(int st_num,int y, int x) {
	int st_y = st[st_num].y;
	int st_x = st[st_num].x;
	for (int b = y; b < st_y+y; b++) {
		for (int a = x; a < st_x+x; a++) {
			if (b < 0 || a < 0 || a >= N || b >= M)continue;
			if (notebook[b][a] == true && st[st_num].arr[b - y][a - x] == true) {
				return false;
			}
			else {
				continue;
			}
		}
	}
	return true;
}

bool draw(int stiker,int dir) {
	if (dir == 0) { // �״��

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check(stiker, i, j) == false) {
					continue;
				}
				else {
					real_draw(stiker, i, j);
					return true;
				}

			}
		}
		return false;




	}
	if (dir == 1) {//90�� ȸ��

	}
	if (dir == 2) {//180

	}
	if (dir == 3) {//270

	}
}

int main() {
	init();
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y>>x;
		st[i].y = y;
		st[i].x = x;
		for (int b = 0; b < y; b++) {
			for (int a = 0; a < x; a++) {
				int imsi; cin >> imsi;
				st[i].arr[b][a] = imsi;
			}
		}
	}
	// 1. ���� ������ ��ƼĿ ���̱�
	// 2. �ڸ� ������ 90�� ȸ���� ���̱�
	// 3. 4�� ȸ�� �ߴµ� �����̸� pass
	// 4. ��������� �� ���� ũ�� ���ϱ�

	

	for (int i = 0; i < K; i++) {// ��ƼĿ����

		for (int j = 0; j < 4; j++) {// 4����
			if (draw(i, j) == false) {
				continue;
			}
			else {
				break;
			}
		}
		cout << "----------------" << endl;
		print();
		cout << "------------------" << endl;


	}
	






	/*for (int i = 0; i < K; i++) {
		int y = st[i].y;
		int x = st[i].x;
		for (int b = 0; b < y; b++) {
			for (int a = 0; a < x; a++) {
				cout << st[i].arr[b][a] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;*/

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}