#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

string expression = "100-200*300-500+20";

long long solution(string expression) {
	long long answer = 0;

	int plusCnt=0;
	int minusCnt=0;
	int mulCnt=0;

	vector<int>num;
	vector<string>yun;

	string imsi;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			imsi.push_back(expression[i]);
		}
		else {
			num.push_back(stoi(imsi));
			imsi = "";
			if (expression[i] == '-') {
				yun.push_back("-");
				minusCnt++;
			}
			else if (expression[i] == '*') {
				yun.push_back("*");
				mulCnt++;
			}
			else if (expression[i] == '+') {
				yun.push_back("+");
				plusCnt++;
			}
		}
		if (i+1 == expression.length()) {
			num.push_back(stoi(imsi));
		}
	}


	// 1. *-+
	string imsi;
	for (int i = 0; i < mulCnt; i++) {
		
	}
	// 2. *+-
	// 3. -*+
	// 4. -+*
	// 5. +*-
	// 6. +-*

	
	for (int i = 0; i < yun.size(); i++) {
		cout << yun[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}


	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	solution(expression);




	return 0;
}
