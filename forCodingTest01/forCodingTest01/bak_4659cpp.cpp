#include <bits/stdc++.h>

using namespace std;

//����(a, e, i, o, u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
//������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�.
//���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.
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