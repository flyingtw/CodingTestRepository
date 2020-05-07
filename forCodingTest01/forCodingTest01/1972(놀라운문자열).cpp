#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

//모든 D에 대해 D-유일하면, 이 문자열을 정말이지 ‘놀라운 문자열’이라고 한다. 
//문자열이 주어질 때, 이 문자열이 놀라운 문자열인지 아닌지를 구하는 프로그램을 작성하시오.

bool solution(string s) {
	bool flag = true;
	
	int sNum = s.length();
	int total_num = sNum - 1;
	int num = total_num;
	int length = 1;
	vector<string>imsi;
	for (int i = 0; i < total_num; i++) {
		for (int j = 0; j < num; j++) {
			string a;
			a.push_back(s[j]);
			a.push_back(s[j + length]);
			if (imsi.empty()) {
				imsi.push_back(a);
				continue;
			}
			vector<string>::iterator iter;
			iter = find(imsi.begin(), imsi.end(), a);
			if (iter == imsi.end()) {//imsi 벡터에 없으면 넣어주기
				imsi.push_back(a);
			}
			else {//중복이 있으면
				flag = false;
				return flag;
			}
			//cout << s[j] << s[j + length] << " ";
		}
		//cout << "임시" << imsi[0] << endl;
		imsi.clear();
		length++;
		num--;
		//cout << endl;
	}



	return flag;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string s;
	bool flag = false;
	
	while (1) {
		cin >> s;
		if (s[0] == '*') {
			break;
		}
		if (solution(s)) {
			cout << s << " is surprising." << endl;
		}
		else {
			cout << s << " is NOT surprising." << endl;
		}
	}
	return 0;
}