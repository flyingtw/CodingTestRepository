#include <iostream>
#include <vector>
#include <string>
#include <stack>


#define endl "\n"

using namespace std;


//(0/(0))

//1. 괄호 쌍 반환하는 함수
vector<pair<int, int>>ReturnPair(string s) {
	vector<pair<int, int>>v;

	stack<int>st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')' ) {
			v.push_back(make_pair(st.top(), i));
			st.pop();

		}
		else {
			continue;
		}
	}
	return v;
}



//2. 조합으로 문자열 출력하는 함수
void PrintAll(vector<pair<int, int>>v2) {



}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<pair<int, int>>v1;

	/*
	v.push_back(make_pair(1, 2));
	v.push_back(make_pair(4, 5));
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	*/
	string s;
	cin >> s;
	v1=ReturnPair(s);
	for (int i = 0; i < v1.size(); i++) {
		cout <<i<<" "<< v1[i].first << " " << v1[i].second << endl;
	}
	PrintAll(v1);
	
	




	return 0;
}
