#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

// �Ӹ���� : �յڰ� �Ȱ��� ��ȭ��ȣ
// ���������� �ռ��°� ���

string s;
int arr[30];
string ret = "";
int odd=-1;
stack <pair<char, int>>st;
char center;

int main() {
	init();
	cin >> s;
	
	int n = s.length();
	for (int i = 0; i < n; i++) {
		arr[s[i] - 'A']++;
	}
	bool even = false;
	for (int i = 0; i < 30; i++) {
		if ((arr[i] & 1) == 1 ) {//Ȧ���̸�
			if (even == false) {
				even = true; 
				odd = i;
			}
			else {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
		}
		
	}

	bool flag2 = false;
	for (int i = 0; i < 30; i++) {
		if ((arr[i] & 1) != 1 && i > odd) {//¦���ε� odd���� ũ�� odd center ó��
			flag2 = true;
			arr[odd]-=1;
			break;
		}
	}


	for (int i = 0; i < 30; i++) {
		if (arr[i] == 0)continue;
		int m = arr[i] / 2;
		
		st.push({ i + 'A',m });
		for (int j = 0; j < m; j++) {
			ret += i + 'A';
			
		}
		
	}

	if (odd!= -1 && flag2 == true) {// Ȧ���ϳ� ������ Ȧ�� ���ĺ��� �ڿ� ������ ����� �ϳ� �߰�
		ret += odd + 'A';
	}
	if (odd != -1 && flag2 == false) {// Ȧ�� �ϳ� ������ �� ���ĺ��� �� �ڸ� ����� �߰�
		
		for (int i = 0; i < arr[odd] - 1; i++) {
			ret += odd + 'A';
		}
		
	}
	while (!st.empty()) {
		int num=st.top().second;
		char c2 = st.top().first;

		
		for (int i = 0; i < num; i++) {
			ret += c2;
		}
		st.pop();
	}
	cout << ret;




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}