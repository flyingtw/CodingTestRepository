#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, M;
int W;
int arr[501][501];
vector<int>H;
int ret = 0;



void init();

int main() {
	init();

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> W;
		H.push_back(W);
		for (int j = 0; j < W; j++) {
			arr[i][j] = 1;
		}
	}


	/*
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	for (int i = 1; i < M-1; i++) {
		int me = H[i];

		int left = 0;
		for (int j = i; j >= 0; j--) {
			if (H[j] > me) {
				left = max(left, H[j]);
			}
		}

		int right = 0;
		for (int j = i; j < M; j++) {
			if (H[j] > me) {
				right = max(right, H[j]);
			}
		}
		
		/*cout << "---------" << endl;
		cout << "left : " << left << endl;
		cout << "me : " << me << endl;
		cout << "rifht : " << right << endl;
		*/

		int a = min(right, left)-H[i];
		//cout << "a : " << a << endl;
		if (a > 0) {
			ret += a;
		}
		





	}
	cout << ret << endl;


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}