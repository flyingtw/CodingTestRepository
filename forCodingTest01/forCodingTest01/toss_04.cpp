#include <bits/stdc++.h>
using namespace std;

string s;
vector<string>v;
stack<string>st;




void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
void print(stack<string>st) {
	int cnt = 0;
	while (!st.empty()) {
		if (cnt == 5) {
			break;
		}
		else {
			cout << st.top() << " ";
			st.pop();
			cnt++;
		}
	}
	cout << "\n";
}

bool check(string s1) {
	bool flag = true;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s1) {
			flag = false;
			break;
		}
	}

	
	return flag;
}

int main() {
	do {
		cin >> s;
		
		if (check(s) == false) {
			print(st);
			continue;
		}
		else {
			v.push_back(s);
			st.push(s);
			print(st);
		}

	} while (getc(stdin) == ' '); 
	

	

	return 0;
}