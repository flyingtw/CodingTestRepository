#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

string s;
string s2="";


//1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
//2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.

//3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.

//4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
//5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.

//6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
//���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
//7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.

void fc7(string s1) {
	if (s1.length() <= 2) {
		while (s1.length() < 3) {
			s1.push_back(s1[s1.length() - 1]);
		}
	}
	s = s1;
}

void fc6(string s1) {
	if (s1.length() >= 16) {
		s1.erase(15, s1.length());
	}
	s = s1;
}

void fc5(string s1) {
	
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == ' ') {
			s1[i] = 'a';
		}
	}
	s = s1;
}

void fc4(string s1) {
	if (s1[s.length() - 1] == '.') {
		s1.erase(s1.length() - 1, s1.length() - 1);
	}
	if (s1[0] == '.') {
		s1.erase(0, 1);
	}
	if (s1.length() == 0)s1.push_back(' ');
	s = s1;
}

void fc3(string s1) {


	for (int i = 0; i < s1.length()-1; i++) {
		if (s1[i] == '.' && s1[i+1]=='.') {
			s1=s1.erase(i, 1);
			i--;
		}
	}
	s = s1;
	
}

void fc2(string s1) {
	string tmp = "";
	for (int i = 0; i < s1.length(); i++) {
		if ((s[i]>='a' && s[i]<='z') ||(s1[i] >= '0' && s1[i] <= '9') || s1[i]=='-' || s1[i]=='_' || s1[i]=='.') {
			tmp.push_back(s1[i]);
		}
		else {
			tmp.push_back(' ');
		}
	}
	s = tmp;
}

void fc1(string s1) {
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] >= 'A' && s1[i] <= 'Z') {
			s1[i] = tolower(s1[i]);
		}
	}
}

int main() {
	init();
	
	cin >> s;
	fc1(s);
	fc2(s);
	fc3(s);
	
	fc4(s);
	
	fc5(s);
	fc6(s);
	
	fc4(s);
	
	fc7(s);
	if (s =="") {
		s = "aaa";
	}
	
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}