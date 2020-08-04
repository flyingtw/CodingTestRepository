#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, M;
vector<int>v;
vector<int>v3;
int cnt = 0;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void combi(int here) {
	if ((int)v3.size() == 2) {
		int n=0;
		for (auto it : v3) {
			n+=v[it];
		}
		if (n == M) { cnt++; }
		return;
	}
	for (int i = here + 1; i < N; i++) {
		v3.push_back(i);
		combi(i);
		v3.pop_back();
	}
}

int main() {
	init();
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	combi(-1);
	cout << cnt;


	return 0;
}
