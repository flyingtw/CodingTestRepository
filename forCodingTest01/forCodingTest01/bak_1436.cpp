#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N;
int cnt = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;
	for (int i = 666;; i++) {
		string s = to_string(i);
		if (s.find("666") != -1) {
			cnt++;
		}
		if (cnt == N) {
			cout << i;
			break;
		}
	}
	






	return 0;
}
