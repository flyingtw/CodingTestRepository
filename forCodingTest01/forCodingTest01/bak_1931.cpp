#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
vector<pair<int, int>>v;
int ed;
int ret = 1;


bool cmp(pair<int, int>v1, pair<int, int>v2) {
	if (v1.second == v2.second) {
		return v1.first < v2.first;
	}
	else {
		return v1.second < v2.second;
	}
}


int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	ed = v[0].second;
	for (int i = 1; i < (int)v.size(); i++) {
		if (ed <= v[i].first) {
			ret++;
			ed = v[i].second;
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