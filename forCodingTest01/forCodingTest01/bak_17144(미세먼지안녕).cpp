#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// 1. Ȯ�� (4���� -> arr/5, ������ -> arr-(arr/5)*Ȯ�갹��)
// 2. ���� û����
// ���� �ݽð�, �Ʒ��� �ð�

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