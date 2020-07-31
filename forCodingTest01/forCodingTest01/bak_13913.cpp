#include <bits/stdc++.h>
using namespace std;
int dx[3] = { 1,-1,2 };
int N, K;
queue<int>q;
int num = 0;

int main() {
	q.push(N);
	while (!q.empty()) {
		int cur_x = q.front();
		q.pop();

		if (cur_x == K) {
			cout << num;
		}

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) {
				nx = cur_x * 2;
			}
			else {
				nx = cur_x + cur_x * dx[i];
			}

			if (nx > K)continue;
			q.push(nx);
			num++;
		}
	}
	

	return 0;
}