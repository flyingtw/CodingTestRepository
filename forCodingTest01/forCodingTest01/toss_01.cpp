#include <bits/stdc++.h>
using namespace std;




string s;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			if (s[i + 1] != '2') { 
				
				cout << "false";
				exit(0);
			}
		}
		else {
			continue;
		}
	}
	cout << "true";

	




	return 0;
}