// �����̵� �������, ���� ������ �ּҰ��� ã�µ� ��� �߰��Ǵ� ���� ������ ã�� ����̴�
// deque(��)�� ����Ѵ�. (��, �ڿ��� �ְ� ���� ���� - vector���� ���� ȿ����)
// dqeue<pair<int,long long>> dq �������� ������ ���� �ε����� ���� ���� �־ ����� �� �ִ�. 

#include <iostream>
#include <deque>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, L;
deque<pair<int,long long>>dq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	long long tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		
		//������ ���� dq�� �ִ� ������ ũ�� �̾ƹ�����
		while (!dq.empty() && dq.back().second > tmp)dq.pop_back();
		dq.push_back({ i,tmp });
		while (i - dq.front().first >= L)dq.pop_front();
		cout << dq.front().second << endl;
	}



	return 0;
}