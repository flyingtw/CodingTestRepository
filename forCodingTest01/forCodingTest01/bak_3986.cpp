#include <bits/stdc++.h>
using namespace std;


int N;
string s;
int num = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char>st;cin >> s;
		st.push(s[0]);
		int m = s.length();
		for (int j = 1; j < m; j++) {
			if (!st.empty() && st.top() == s[j]) {
				st.pop();	
			}
			else {
				st.push(s[j]);
			}
		}
		if (st.size()==0)num++;
	}
	cout << num;

	return 0;
}