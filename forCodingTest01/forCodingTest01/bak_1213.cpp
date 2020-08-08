#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// 팰린드롬 : 앞뒤가 똑같은 전화번호
// 사전순으로 앞서는것 출력

string s;
int arr[30];
string ret = "";
int odd=-1;
stack <pair<char, int>>st;
char center;

int main() {
	init();
	cin >> s;
	
	int n = s.length();
	for (int i = 0; i < n; i++) {
		arr[s[i] - 'A']++;
	}
	bool even = false;
	for (int i = 0; i < 30; i++) {
		if ((arr[i] & 1) == 1 ) {//홀수이면
			if (even == false) {
				even = true; 
				odd = i;
			}
			else {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
		}
		
	}

	bool flag2 = false;
	for (int i = 0; i < 30; i++) {
		if ((arr[i] & 1) != 1 && i > odd) {//짝수인데 odd보다 크면 odd center 처리
			flag2 = true;
			arr[odd]-=1;
			break;
		}
	}


	for (int i = 0; i < 30; i++) {
		if (arr[i] == 0)continue;
		int m = arr[i] / 2;
		
		st.push({ i + 'A',m });
		for (int j = 0; j < m; j++) {
			ret += i + 'A';
			
		}
		
	}

	if (odd!= -1 && flag2 == true) {// 홀수하나 들어오고 홀수 알파벳이 뒤에 있으면 가운데에 하나 추가
		ret += odd + 'A';
	}
	if (odd != -1 && flag2 == false) {// 홀수 하나 들어오고 그 알파벳이 맨 뒤면 가운데에 추가
		
		for (int i = 0; i < arr[odd] - 1; i++) {
			ret += odd + 'A';
		}
		
	}
	while (!st.empty()) {
		int num=st.top().second;
		char c2 = st.top().first;

		
		for (int i = 0; i < num; i++) {
			ret += c2;
		}
		st.pop();
	}
	cout << ret;




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}