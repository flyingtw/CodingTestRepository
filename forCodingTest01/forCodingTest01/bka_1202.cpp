#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, K;

vector<pair<int, int>>v;
vector<int>vv;


int main() {
	init();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		v.push_back({ M,V });
	}
	for (int i = 0; i < K; i++) {
		int C; cin >> C;
		vv.push_back(C);
	}
	
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());

	for (auto it : vv) {
		
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}