#include<iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, C;
vector<long long>house;



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

}




int main() {
	init();
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	
	//mid ��(���� �Ÿ�)�� �����ش�. 
	// n��° ���� n+1 ���� �� ������ �Ÿ��� mid���� ������
	long long answer = 0;

	long long left = 1;
	long long right = house[house.size() - 1]-house[0];
	while (left <= right) {
		int cnt = 1;
		int current = 0;
		long long mid = (right + left) / 2;
		for (int i = 1; i < house.size(); i++) {
			int dist = house[i] - house[current];
			if (dist >= mid) {//�츮�� ���Ѱ����� �Ÿ��� �� ��ų� ������(���� �����ϸ�)
				cnt++;
				current = i;
			}
		}
		if (cnt >= C) {//�����Ⱑ �ʹ� ���� ��ġ�� -> �Ÿ��� �ʹ� ����
			answer = mid;
			left = mid + 1;
			
		}
		else {
			right=mid-1;//�����Ⱓ �Ÿ� �����ֱ�
		}
	}



	cout << answer << endl;

	return 0;
}