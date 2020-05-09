#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

int N;//파일의 갯수
string pattern;//별 포함된 패턴(별은 양 끝에 있지 않음)

int first;
int second;


string solution(string s) {
	string result = "DA";//YES (패턴 일치), NE : no
	for (int i = 0; i <= first; i++) {
		if (s[i] == pattern[i]) {
			result = "DA";
		}
		else {
			result = "NE";
			break;
		}
	}
	int second_idx = s.length() - (pattern.length() - second);

	for (int i = second_idx; i < s.length() - 1; i++) {
		if (s[i] == pattern[first + 2 + i]) {
			result = "DA";
		}
		else {
			result = "NE";
			break;
		}
	}



	return result;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> N;
	cin >> pattern;
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '*') {
			first = i - 1;
			second = i + 1;
			break;
		}
	}
	


	string s;
	vector<string>imsi;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s[0] != pattern[0]) {
			imsi.push_back("NE");
		}
		
		else {
			imsi.push_back(solution(s));
		}
		
		
	}


	for (int i = 0; i < imsi.size(); i++) {
		cout << imsi[i] << endl;
	}

	return 0;
}
