#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

vector<int>v;

int main() {
	init();

	v.push_back(4);
	for (int i = 0; i<3 ; i++) {
		v.push_back(3-i);
	}
	do {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;

	} while (prev_permutation(v.begin(), v.end()));
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}