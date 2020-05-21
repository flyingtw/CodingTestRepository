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
	
	//mid 값(적정 거리)를 정해준다. 
	// n번째 집과 n+1 번쨰 집 사이의 거리가 mid보다 작으면
	long long answer = 0;

	long long left = 1;
	long long right = house[house.size() - 1]-house[0];
	while (left <= right) {
		int cnt = 1;
		int current = 0;
		long long mid = (right + left) / 2;
		for (int i = 1; i < house.size(); i++) {
			int dist = house[i] - house[current];
			if (dist >= mid) {//우리가 정한값보다 거리가 더 길거나 같으면(조건 충족하면)
				cnt++;
				current = i;
			}
		}
		if (cnt >= C) {//공유기가 너무 많이 설치됨 -> 거리가 너무 좁음
			answer = mid;
			left = mid + 1;
			
		}
		else {
			right=mid-1;//공유기간 거리 좁혀주기
		}
	}



	cout << answer << endl;

	return 0;
}