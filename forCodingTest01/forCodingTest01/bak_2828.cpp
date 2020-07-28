#include <bits/stdc++.h>

using namespace std;
 
int N, M, J;
int answer = 0;


int main() {
	cin >> N >> M;
	cin >> J;
	int start = 1; int end = M;
	for (int i = 0; i < J; i++) {
		//cout << "i :" << i << endl;
		int apple; cin >> apple;
		if (apple >= start && apple <= end) {
			//cout << "start : " << start << endl;
			//cout << "end : " << end << endl;
		}
		else if (apple > end) {
			//바구니보다 오른쪽에 있으면
			answer += (apple - end);
			start = apple-M+1;
			end = apple;
			//cout << "start : " << start << endl;
			//cout << "end : " << end << endl;
		}
		else {
			answer += (start - apple);
			start = apple;
			end = apple + M - 1;
			//cout << "start : " << start << endl;
			//cout << "end : " << end << endl;
		}
		
	}
	cout << answer;
	return 0;
}