// 슬라이딩 윈도우란, 범위 내에서 최소값을 찾는등 계속 추가되는 범위 내에서 찾는 방법이다
// deque(덱)을 사용한다. (앞, 뒤에서 넣고 빼고가 쉬움 - vector보다 좀더 효율적)
// dqeue<pair<int,long long>> dq 형식으로 쌍으로 만들어서 인덱스와 값을 같이 넣어서 사용할 수 있다. 

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
		
		//들어오는 값이 dq에 있는 값보다 크면 뽑아버리기
		while (!dq.empty() && dq.back().second > tmp)dq.pop_back();
		dq.push_back({ i,tmp });
		while (i - dq.front().first >= L)dq.pop_front();
		cout << dq.front().second << endl;
	}



	return 0;
}