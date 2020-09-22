#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


int bridge_length = 100;
int weight = 100;
vector<int> truck_weights = { 10 };


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<int>dq;
	deque<int>v;
	int n = (int)truck_weights.size();
	for (int i = 0; i < n; i++) {
		dq.push_back(truck_weights[i]);
    }
	int t = 0;
	v.push_back(0);
	while (!dq.empty() && !v.empty()) {
		
		t++;

		int cur = dq.front();
		

		int w = 0;//다리위 총 무게
		int l = (int)v.size();//다리위 총 길이

		for (auto a : v) {
			w += a;
		}
		
		if (w + cur <= weight && l + 1 <= bridge_length) {// 무게 추가하고 길이 ㄱㅊ하면 추가
			v.push_back(cur);
			dq.pop_front();
		}
		else {
			v.push_back(0);
		}


		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		

		if (v.size() == bridge_length) {
			v.pop_front();
		}


	}
	cout << t+2 << endl;

	



    return answer;
}




int main() {
	init();
	solution(bridge_length, weight, truck_weights);

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}