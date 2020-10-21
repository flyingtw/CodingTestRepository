#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, K;
bool visited[500001];

int ret = 0;

int d1[3] = { 2,1,1 };
int d2[3] = { 0,-1,1 };

//아! +1, -1  보다 *2 한값이 더 빨리 찾아질수 있는데 그걸 고려해야함

int bfs(int N) {
	visited[N] = true;
	queue<int>q;
	q.push(N);
	int t = 0;
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int cur = q.front();
			q.pop();
			if (cur == K) {
				return t;
			}
			for (int i = 0; i < 3; i++) {
				int new_cur = cur * d1[i] + d2[i];
				if (new_cur < 0 || new_cur>500000)continue;
				if (visited[new_cur] == false) {
					q.push({ new_cur });
					visited[new_cur] = true;
				}
			}
		}
		t++;
		K = K + t;
	}
}

int main() {
	init();

	//5 17 -> 2
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		exit(0);
	}

	ret=bfs(N);
	cout<<ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}