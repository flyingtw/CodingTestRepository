#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
char arr[51][51];
int ppl_y, ppl_x;
int exit_y, exit_x;
int x_cnt = 0;
// ��� X�� ������ �ִܰ��
// S�� ���� E ���� ���� ���� ����� X1 ����
// X1�κ��� E ���� ���� ���� ����� X2 ����
// ....Xn ���κ��� E ���� ���� ���� ����� ��� ����
// �� x �� ���������� �ʱ�ȭ(�Դ��� �� �� �� �����ϱ�)


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