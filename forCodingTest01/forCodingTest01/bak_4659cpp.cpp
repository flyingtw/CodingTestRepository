#include <bits/stdc++.h>

using namespace std;

//모음(a, e, i, o, u) 하나를 반드시 포함하여야 한다.
//모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
//같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
string s1 = " ";
char check[5] = { 'a','e','i','o','u' };

bool flag1 = false;
bool flag2 = false;
bool mo = false;
bool flag3 = false;

int main() {
	
	while (1) {
		cin >> s1;
		if (s1 == "end") break;
		int cnt = 0;
		for (int i = 0; i < s1.length(); i++) {

			for (int j = 0; i < 5; j++) {
				if (s1[i] == check[j]) {
					flag1 = true;
					mo = true;
				}
				else {
					if (mo == true) {
						cnt++;
					}
					else {
						cnt = 0;
					}
					
				}
			}
			

			if (i > 0) {
				if (s1[i] == s1[i - 1]) {
					if (s1[i] == 'e' || s1[i] == 'o') {
						flag3 = true;
					}
				}
			}

			
			




		}

	}
	



	return 0;
}