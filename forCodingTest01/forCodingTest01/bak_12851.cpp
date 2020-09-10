#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];

int d1[] = { 1,1,2 };
int d2[] = { -1,1,0 };

int ret = 0;
int level = 0;

void bfs(int x) {
	visited[x] = true;
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int q_size = (int)q.size();
		while (q_size--) {
			int cur_x = q.front();
			visited[cur_x] = true;
			q.pop();
			if (cur_x == K)ret++;
			for (int i = 0; i < 3; i++) {
				int nx = cur_x * d1[i] + d2[i];
				if (nx<0 || nx>100000)continue;
				if (!visited[nx]) {
					q.push(nx);
					
				}
			}
		}
		if (ret)break;
		level++;
	}
}


int main() {

	cin >> N >> K;
	bfs(N);
	cout << level << endl;
	cout << ret << endl;
	return 0;
}