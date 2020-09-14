#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

string s;
string s2="";


//1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
//2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.

//3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.

//4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
//5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.

//6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

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