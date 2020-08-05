#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N,M;
int arr[51][51];

// 이거슨 조합문제이다
// 각 집(1) 으로부터 치킨집(2) 까지의 최소거리를 구한다음에 몇개씩 뺀다음에 합을 구하고 그중의 최소값을 구하면됨
void init();


int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout<< arr[i][j]<<" ";
		}
	}

	return 0;
}


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}