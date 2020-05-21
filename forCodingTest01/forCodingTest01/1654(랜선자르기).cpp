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
	// k : 가지고 있는 랜선의 갯수
	// N : 만들기를 원하는 랜선의 갯수
	// lens : 모든 랜선 각각의 길이들
	// answer : 이 길이로 짤라야 N개로 만들 수 있다. 
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
		if (cnt >= N) {// mid가 너무 작아
			answer = mid;
			left = mid + 1;

		}
		else if (cnt < N) {// mid가 너무 커 (몇개 안짤렸어)
			right = mid - 1;
		}
		
	}
	cout << answer << "\n";


	return 0;
}