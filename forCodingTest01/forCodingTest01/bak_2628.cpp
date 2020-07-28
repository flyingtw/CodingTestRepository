#include <bits/stdc++.h>

using namespace std;

int M, N;
int t;
vector<int>vm;
vector<int>vn;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	cin >> t;
	vn.push_back(0);
	vm.push_back(0);
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 0) {
			vn.push_back(y);
		}
		if (x == 1) {
			vm.push_back(y);
		}
	}
	vn.push_back(N);
	vm.push_back(M);
	sort(vn.begin(), vn.end());
	sort(vm.begin(), vm.end());
	int n_max = 0;
	int m_max = 0;
	for (int i = 0; i < vn.size()-1;i++) {
		n_max = max(vn[i + 1] - vn[i], n_max);
	}
	for (int i = 0; i < vm.size() - 1; i++) {
		m_max = max(vm[i + 1] - vm[i], m_max);
	}
	cout << n_max * m_max << "\n";


	return 0;
}