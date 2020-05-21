#include<iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int K;
long long N;
vector<long long>lens;




int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	// k : ������ �ִ� ������ ����
	// N : ����⸦ ���ϴ� ������ ����
	// lens : ��� ���� ������ ���̵�
	// answer : �� ���̷� ©��� N���� ���� �� �ִ�. 
	long long answer = 0;

	cin >> K >> N;
	long long max = 0;
	for (int i = 0; i < K; i++) {
		
		long long tmp;
		cin >> tmp;
		if (tmp > max) {
			max = tmp;
		}
		lens.push_back(tmp);
	}
	//sort(lens.begin(), lens.end());

	long long left = 1;
	long long right = max;
	while (left <= right) {
		long long cnt = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < lens.size(); i++) {
			cnt += (lens[i] / mid);
		}
		if (cnt >= N) {// mid�� �ʹ� �۾�
			answer = mid;
			left = mid + 1;

		}
		else if (cnt < N) {// mid�� �ʹ� Ŀ (� ��©�Ⱦ�)
			right = mid - 1;
		}
		
	}
	cout << answer << "\n";


	return 0;
}