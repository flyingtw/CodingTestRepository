#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N,M;
int arr[51][51];


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