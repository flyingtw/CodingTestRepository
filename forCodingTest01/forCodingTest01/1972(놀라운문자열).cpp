#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

//��� D�� ���� D-�����ϸ�, �� ���ڿ��� �������� ������ ���ڿ����̶�� �Ѵ�. 
//���ڿ��� �־��� ��, �� ���ڿ��� ���� ���ڿ����� �ƴ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
			if (iter == imsi.end()) {//imsi ���Ϳ� ������ �־��ֱ�
				imsi.push_back(a);
			}
			else {//�ߺ��� ������
				flag = false;
				return flag;
			}
			//cout << s[j] << s[j + length] << " ";
		}
		//cout << "�ӽ�" << imsi[0] << endl;
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