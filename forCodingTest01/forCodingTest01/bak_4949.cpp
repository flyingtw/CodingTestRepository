#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// ( �� [ �ΰ��� ��ȣ
// 
string s;
stack<char>st;
stack<char>imsi;
vector<string>v;

int main() {
	init();
	while (1) {
		bool flag = true;
		getline(cin, s);
		if (s == ".") {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << endl;
			}
			break;
		}
		st = imsi;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[') {// �����°�
				st.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']') {// �����°Ÿ�
				if (st.empty() == true) {
					flag = false;
					break;
				}
				else {
					char c = st.top();
					if (s[i] == ')' && c != '(') {
						flag = false;
						break;
					}
					else if (s[i] == ']' && c != '[') {
						flag = false;
						break;
					}
					else {
						st.pop();
					}
				}
			}
			else {//��ȣ�� �ƴϸ� pass
				continue;
			}
			
		}
		if (flag==false) {
			v.push_back("no");
			
		}
		else {
			if (st.empty() == true) {
				v.push_back("yes");
			}
			else {
				v.push_back("no");

			}

		}



		
		
	}





	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}