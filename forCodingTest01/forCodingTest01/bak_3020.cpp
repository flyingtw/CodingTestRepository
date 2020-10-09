#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, H;

vector<int>va;//È¦¼ö
vector<int>vb;//Â¦¼ö


int main() {
	init();



	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		int imsi; cin >> imsi;
		if (i & 1) {
			vb.push_back(imsi);
		}
		else {
			va.push_back(imsi);
		}
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int ret = 0;
	cout << "--------" << endl;

	for (int i = 1; i <=H; i++) {
		ret = 0;
		ret += lower_bound(va.begin(), va.end(), i) - va.begin();
		ret += lower_bound(vb.begin(), vb.end(), H-i-1) - vb.begin();
		cout << ret << endl;
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}