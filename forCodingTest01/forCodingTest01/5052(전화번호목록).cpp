#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int t;

int main() {
	init();

	cin >> t;
	for (int a = 0; a < t; a++) {
		int tc; cin >> tc;
		vector<string>v;
		bool flag = true;
		for (int i = 0; i < tc; i++) {
			string s; cin >> s;
			
			if (v.empty()) {
				v.push_back(s);
			}
			else {
				for (int j = 0; j < i; j++) {
					if (flag == true) {
						for (int k = 0; k < (int)v[j].size(); k++) {
							if (v[j][k] != s[k]) {
								flag = false;
								break;
							}
							else {

							}
						}
					}
					else {
						break;
					}
				}
			}
			
		}
		if (flag == false) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}