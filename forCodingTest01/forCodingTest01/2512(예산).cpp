#include<iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N;//3�̻� 10,000����
vector<int>jibang;//�� ������ ���ϴ� �����
int total_money;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

}




int main() {
	init();
	int result = 0;

	cin >> N;
	int tmp;
	int biggest=0;
	long long want_money_sum = 0;


	for (int i = 0; i < N; i++) {
		cin >> tmp;
		jibang.push_back(tmp);
		if (tmp > biggest) {
			biggest = tmp;
		}
		want_money_sum += tmp;
	}
	cin >> total_money;

	
	if (want_money_sum < total_money) {//��ü ���ϴ� �ݾ��� �� ���꺸�� ������ �ְ� ���Ѿ��� �䱸 ������� �ִ밪
		result = biggest;
	}
	else {// 0~biggest ������ ���߿� �̺�Ž���� �̿��� �ִ밪�� ã��
		int left = 0;
		int right = biggest;
		while (left <= right) {
			int mid = (left + right) / 2;
			long long tmp_sum = 0;
			for (int i = 0; i < N; i++) {
				if (jibang[i] < mid) {
					tmp_sum += jibang[i];
				}
				else {
					tmp_sum += mid;
				}
			}

			if (tmp_sum > total_money) {//������ �ִ� ������� ������ ��� right�� �ϳ� ���������� ����
				right = mid - 1;
			}
			else if (tmp_sum < total_money) {// ������ �ִ� ������� �γ��Ұ�� left�� �ϳ� mid���� �ϳ� ū������ 
				left = mid + 1;
				result = mid;//�ִ� ����� mid�� �ϴ� ����
			}
			else {
				result = mid;
				break;
			}
		}
	}
	




	cout << result;
	return 0;
}