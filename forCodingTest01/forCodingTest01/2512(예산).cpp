#include<iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N;//3이상 10,000이하
vector<int>jibang;//각 지방이 원하는 예산들
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

	
	if (want_money_sum < total_money) {//전체 원하는 금액이 총 예산보다 작으면 최고 상한액은 요구 예산액중 최대값
		result = biggest;
	}
	else {// 0~biggest 사이의 값중에 이분탐색을 이용해 최대값을 찾기
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

			if (tmp_sum > total_money) {//설정한 최대 예산안이 오버될 경우 right를 하나 작은값으로 변경
				right = mid - 1;
			}
			else if (tmp_sum < total_money) {// 설정한 최대 예산안이 널널할경우 left를 하나 mid보다 하나 큰값으로 
				left = mid + 1;
				result = mid;//최대 예산안 mid로 일단 저장
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