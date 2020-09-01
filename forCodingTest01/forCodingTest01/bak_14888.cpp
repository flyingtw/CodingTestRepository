#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// next_permutation을 활용하자
int max_ret = -1e9;
int min_ret = 1e9;

int N;
vector<int>v;
vector<int>yun;

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int b; cin >> b;
		for (int j = 0; j < b; j++) {
			yun.push_back(i);
		}
	}
	/*for (int i = 0; i<(int)yun.size(); i++) {
		cout << yun[i] << " ";
	}*/
	do {
		int tmp = v[0];
		for (int i = 0; i < (int)yun.size(); i++) {
			if (yun[i] == 0) {
				tmp = tmp + v[i + 1];
			}
			if (yun[i] == 1) {
				tmp = tmp - v[i + 1];
			}
			if (yun[i] == 2) {
				tmp = tmp * v[i + 1];
			}
			if (yun[i] == 3) {
				tmp = tmp / v[i + 1];
			}
			
		}
		max_ret = max(max_ret, tmp);
		min_ret = min(min_ret, tmp);
		

	} while (next_permutation(yun.begin(), yun.end()));

	cout << max_ret << endl;
	cout << min_ret << endl;
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}