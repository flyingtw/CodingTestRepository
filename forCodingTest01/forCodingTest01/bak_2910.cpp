#include <bits/stdc++.h>

using namespace std;

int N, C;
int arr[1000000000];
vector<pair<int, int>>v1;

bool compare(pair<int, int> a, pair<int, int> b) {
	
	return a.second > b.second;
}


int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		arr[a]++;
	}
	for (int i = 0; i < 1000000000; i++) {
		if (arr[i] > 0) {
			v1.push_back({ i,arr[i] });
		}
	}
	sort(v1.begin(), v1.end(), compare);
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].second; j++) {
			cout << v1[i].first << " ";
		}
	}

	return 0;
}