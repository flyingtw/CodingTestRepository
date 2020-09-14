#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


deque<int>dq;
vector<int> ball ;
vector<int> order;
queue<int>wait;
queue<int>q;
vector<int>ret;

vector<int> solution(vector<int> ball, vector<int> order) {

	vector<int> answer;
	for (int i = 0; i < (int)ball.size(); i++) {
		dq.push_back(ball[i]);
	}
	for (int i = 0; i < (int)order.size(); i++) {
		q.push(order[i]);
	}
	while (!q.empty()) {
		int a = q.front();
		if (dq.front() == a) {
			q.pop();
			dq.pop_front();
			ret.push_back(a);
		}
		else if (dq.back() == a) {
			q.pop();
			dq.pop_back();
			ret.push_back(a);
		}
		else {
			q.pop();
			wait.push(a);
		}
		bool flag = false;
		while (flag == false) {
			int q_size = (int)wait.size();
			while (q_size--) {
				int b = wait.front();
				if (dq.front() == b) {
					wait.pop();
					dq.pop_front();
					ret.push_back(b);
					flag = false;
				}
				else if (dq.back() == b) {
					wait.pop();
					dq.pop_back();
					ret.push_back(b);
					flag = false;
				}
				else {
					wait.pop();
					wait.push(b);
					flag = true;
					continue;
				}
			}
			if (wait.size() == 0)break;
		}
	}
	answer = ret;
	return answer;
}



int main() {
	init();

	solution(ball, order);

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}