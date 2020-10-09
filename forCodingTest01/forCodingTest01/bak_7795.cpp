#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int T, N, M;

vector<int>va;
vector<int>vb;

int ret;

int main() {
	init();
	cin >> T;
	for (int i = 0; i < T; i++) {
		ret = 0;
		cin >> N >> M;
		va.clear();
		vb.clear();
		for (int a = 0; a < N; a++) {
			int imsi; cin >> imsi;
			va.push_back(imsi);
		}
		for (int b = 0; b < M; b++) {
			int imsi; cin >> imsi;
			vb.push_back(imsi);
		}
		//sort(va.begin(), va.end(), greater<>());
		sort(vb.begin(), vb.end());

		for (int j = 0; j < (int)va.size(); j++) {
			ret += lower_bound(vb.begin(), vb.end(), va[j])-vb.begin();
		}
		cout << ret << endl;
	}
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}