#include <bits/stdc++.h>

using namespace std;

//����(a, e, i, o, u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
//������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�.
//���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.

void solution(string s1) {
	cin >> s1;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	int cnt = 0;

	if (s1 == "end") return;


	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
			flag1 = true;
			break;
		}
	}
	if (flag1 == false) {
		
		return ("<" + s1 + ">" + " is not acceptable." + "\n";

	}

	for (int i = 0; i < s1.length() - 1; i++) {
		if (s1[i] == s1[i + 1]) {
			if (s1[i] == 'e' || s1[i] == 'o') continue;
			else {
				//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
				//cout << "2" << endl;
				flag2 = true;
				break;
			}

		}
	}
	if (flag2 == true) continue;
	if (s1.length() > 3) {
		for (int i = 0; i < s1.length() - 3; i++) {
			if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
				if (s1[i + 1] == 'a' || s1[i + 1] == 'e' || s1[i + 1] == 'i' || s1[i + 1] == 'o' || s1[i + 1] == 'u') {
					if (s1[i + 2] == 'a' || s1[i + 2] == 'e' || s1[i + 2] == 'i' || s1[i + 2] == 'o' || s1[i + 2] == 'u') {
						//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
						flag3 = true;
						break;
					}
				}
			}
			if (s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'u') {
				if (s1[i + 1] != 'a' && s1[i + 1] != 'e' && s1[i + 1] != 'i' && s1[i + 1] != 'o' && s1[i + 1] != 'u') {
					if (s1[i + 2] != 'a' && s1[i + 2] != 'e' && s1[i + 2] != 'i' && s1[i + 2] != 'o' && s1[i + 2] != 'u') {
						//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
						//cout << "i : "<<i << endl;
						flag3 = true;
						break;
					}
				}
			}
		}
	}
	if (flag3 == true) {
		cout << "<" << s1 << ">" << " is not acceptable." << "\n";
		//cout << "3" << endl;
	}
	else {
		cout << "<" << s1 << ">" << " is acceptable." << "\n";
		//cout << "4" << endl;
	}
}

int main() {
	string s1 = " ";
	
	cin >> s1;
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	int cnt = 0;

	if (s1 == "end") break;
		
		
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
			flag1 = true;
			break;
		}
	}
	if (flag1 == false) {
		cout << "<" << s1 << ">" << " is not acceptable." << "\n";
		//cout << "1" << endl;
		continue;
	}

	for (int i = 0; i < s1.length() - 1; i++) {
		if (s1[i] == s1[i + 1]) {
			if (s1[i] == 'e' || s1[i]=='o') continue;
			else { 
				//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
				//cout << "2" << endl;
				flag2 = true;
				break;
			}
				
		}
	}
	if (flag2 == true) continue;
	if (s1.length() > 3) {
		for (int i = 0; i < s1.length() - 3; i++) {
			if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
				if (s1[i+1] == 'a' || s1[i+1] == 'e' || s1[i+1] == 'i' || s1[i+1] == 'o' || s1[i+1] == 'u') {
					if (s1[i+2] == 'a' || s1[i+2] == 'e' || s1[i+2] == 'i' || s1[i+2] == 'o' || s1[i+2] == 'u') {
						//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
						flag3 = true;
						break;
					}
				}
			}
			if (s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'u') {
				if (s1[i + 1] != 'a' && s1[i + 1] != 'e' && s1[i + 1] != 'i' && s1[i + 1] != 'o' && s1[i + 1] != 'u') {
					if (s1[i + 2] != 'a' && s1[i + 2] != 'e' && s1[i + 2] != 'i' && s1[i + 2] != 'o' && s1[i + 2] != 'u') {
						//cout << "<" << s1 << ">" << " is not acceptable." << "\n";
						//cout << "i : "<<i << endl;
						flag3 = true;
						break;
					}
				}
			}
		}
	}
	if (flag3 == true) {
		cout << "<" << s1 << ">" << " is not acceptable." << "\n";
		//cout << "3" << endl;
	}
	else {
		cout << "<" << s1 << ">" << " is acceptable." << "\n";
		//cout << "4" << endl;
	}
		

	




	}



	return 0;
}