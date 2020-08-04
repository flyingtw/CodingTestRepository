#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, L, R;
int arr[51][51];

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
	}
}

int main() {
	init();
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	cout << 110 / 3 << endl;



	return 0;
}
