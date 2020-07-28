#define _CRT_SECURE_NO_WARNINGS 

#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int tc, n;
string s1 = "";
vector<string>small;
vector<int>big;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void seperate(string s) {
	char str_buff[100];
	strcpy(str_buff, s.c_str());//string 문자열을 char 문자열로 바꿔줌

	char* tok1 = strtok(str_buff, " ");
	while (tok1 != NULL) {
		cout << tok1 << endl;
		tok1 = strtok(NULL, " ");
	}//토큰으로 잘라서 공백 단위로  구분
}

int main() {
	init();
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cout << "i :" << i << endl;
		cin >> n;
		cin.ignore();
		for (int j = 0; j < n; j++) {
			cout << "j :" << j << endl;
			getline(cin, s1);
			seperate(s1);
			cout << "------" << endl;
		}

	}
	//char a[] = "sunglasses eyewear";
	//char* tok1 = strtok(a , " ");
	//while (tok1 != NULL) {
	//	cout << tok1 << endl;
	//	tok1 = strtok(NULL, " ");
	//}

	return 0;
}