#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
vector<int>v;
int ret = 0;

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		v.push_back(n);
	}
	for (int i = N - 1; i > 0; i--) {
		if (v[i] <= v[i - 1]) {
			ret += v[i - 1] - (v[i] - 1);
			v[i - 1] = v[i] - 1;
		}
	}
	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}