#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

int N;//������ ����
string pattern;//�� ���Ե� ����(���� �� ���� ���� ����)
string start;//�� ����
string second;//�� ����


string solution(string s, int startN, int endN) {
	string result = "DA";//YES (���� ��ġ), NE : no
	if (s.length() < startN + endN ) {
		return "NE";
	}

	for (int i = 0; i < startN; i++) {
		if (s[i] == start[i]) {
			continue;
		}
		else {
			return "NE";
		}
	}

	for (int i = s.length() - endN; i < s.length(); i++) {
		if (s[i] == second[i-s.length()+endN]) {
			continue;
		}
		else {
			return"NE";
		}
	}



	return result;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string>words;

	cin >> N;
	cin >> pattern;
	for (int i = 0; i < N; i++) {
		string imsi;
		cin >> imsi;
		words.push_back(imsi);
	}

	
	bool flag = false;
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '*') {
			flag = true;
			continue;
		}
		if (flag == false) {
			start.push_back(pattern[i]);
		}
		else {
			second.push_back(pattern[i]);
		}
		
	}
	int startN = start.length();
	int endN = second.length();
	//cout << "start :" << start << endl;
	//cout << "end : " << second << endl;
	for (string i : words) {
		cout << solution(i,startN,endN) << endl;
	}
	

	return 0;
}
