#define _CRT_SECURE_NO_WARNINGS 

#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int tc, n;



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void seperate(string s) {
	char str_buff[100];
	strcpy(str_buff, s.c_str());//string ���ڿ��� char ���ڿ��� �ٲ���

	char* tok1 = strtok(str_buff, " ");
	while (tok1 != NULL) {
		cout << tok1 << endl;
		tok1 = strtok(NULL, " ");
	}//��ū���� �߶� ���� ������  ����
}

int main() {
	init();
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n;
		cout << "------" << endl;
		for (int j = 0; j < n; j++) {
			string s1; cin >> s1;// string �� �ƴ϶� getline ���� ���� ��ü�� �޾ƾ���(������� ����)
			seperate(s1);
			
			
		}
		cout << endl;
	}
	//char a[] = "sunglasses eyewear";
	//char* tok1 = strtok(a , " ");
	//while (tok1 != NULL) {
	//	cout << tok1 << endl;
	//	tok1 = strtok(NULL, " ");
	//}

	return 0;
}