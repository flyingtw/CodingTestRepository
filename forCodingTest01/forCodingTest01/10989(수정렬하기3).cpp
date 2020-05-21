#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 10000
using namespace std;

//�Է¹��� N���� ���ڸ� ������������ �����ϱ�
// �ذ� : ��� �������� �̿��� �󵵰� �󸶳� ���� ���Դ����� ���ش�.
int N;
int arr[MAX+1] = { 0, };


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}





int main() {
	init();
	
	cin >> N;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i <= MAX; i++) {
		while (arr[i] != 0) {
			cout << i << endl;
			arr[i]--;
		}
	}


	return 0;
}