#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int n;
vector<char>v;


int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		v.push_back(c);
	}


	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}