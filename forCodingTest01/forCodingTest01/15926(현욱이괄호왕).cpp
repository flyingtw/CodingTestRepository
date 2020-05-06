#include <iostream>
#include <string>
#include <stack>
#include <algorithm>



#define endl "\n"



using namespace std;

int n;
string s;

int solution(int n, string s) {
	int answer = 0;
	stack<int>st;
	st.push(-1);
	
	//int cnt = 0;
	//int num = 1;
	//while (1) {
	//	
	//	cnt++;
	//	for (int i = 0; i < s.length(); i++) {
	//		
	//		if (s[i] == '(' && s[i + 1] == ')') {
	//			
	//			s = s.substr(0, i) + to_string(num)+"x" + s.substr(i + 2);
	//		}
	//		
	//		else if (s[i] == '(' && s[i+2] == 'x' && s[i + 3] == ')') {
	//			num++;
	//			s = s.substr(0, i+1) + to_string(num) + "x" + s.substr(i + 3);
	//		}
	//		cout << s << endl;
	//		if (i == s.length()) break;
	//	}
	//	
	//	
	//}
	//cout << s << endl;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i);

		}
		else {
			st.pop();
			//스택이 비어있지 않으면('('가 남아있으면)
			if (!st.empty()) answer = max(answer, i - st.top());
			else st.push(i);
		}
	}





	return answer;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	
	cout << solution(n, s) << endl;


	return 0;
}