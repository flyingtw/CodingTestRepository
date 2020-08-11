#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int F, S, G, U, D;
int visited[1000001];
int ret;

int bfs(int S) {
	if (S == G)return 0;
	visited[S] = 0;
	queue<int>q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		
		if (cur == G) return visited[cur];
		int cur_U = q.front() + U;
		int cur_D = q.front() - D;
		q.pop();

		if (visited[cur_U] == -1 && cur_U<=F) {
			q.push(cur_U);
			visited[cur_U] = visited[cur] + 1;
		}
		if (visited[cur_D] == -1 && cur_D >= 1) {
			q.push(cur_D);
			visited[cur_D] = visited[cur] + 1;
		}
	}
	return -1;
}

int main() {
	init();
	//F: 전체 //S: 강호위치 //G: 목적지// U: up//D: down
	cin >> F >> S >> G >> U >> D;
	memset(visited, -1, sizeof(visited));
	ret=bfs(S);
	if (ret == -1) {
		cout << "use the stairs";
	}
	else {
		cout << ret;
	}


	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}