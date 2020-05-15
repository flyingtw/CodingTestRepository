#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

string N;
vector<int>numbers(11,0);


/*
�ټ��̴� �������� ������ ���� �̻�Դ�.�ټ��̴� �ڱ� �� ��ȣ�� ���� �ö�ƽ ���ڷ� ���� ���̷��� �Ѵ�.

�ټ����� ���������� �ö�ƽ ���ڸ� �� ��Ʈ�� �Ǵ�.�� ��Ʈ���� 0������ 9������ ���ڰ� �ϳ��� ����ִ�.�ټ����� �� ��ȣ�� �־����� ��, 
�ʿ��� ��Ʈ�� ������ �ּڰ��� ����Ͻÿ�. (6�� 9�� ����� �̿��� �� �ְ�, 9�� 6�� ����� �̿��� �� �ִ�.)
*/
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	//N = "9999";//2
	cin >> N;
	int num=N.size();
	bool flag = false;
	for (int i = 0; i < num; i++) {
		if (N[i] == '6' || N[i] == '9') {
			if (flag == false) {
				numbers[6]++;
				flag = true;
			}
			else {
				numbers[9]++;
				flag = false;
			}
		}
		else {
			numbers[N[i] - '0']++;
		}
	}
	
	
	cout << *max_element(numbers.begin(), numbers.end()) << endl;
	return 0;
}