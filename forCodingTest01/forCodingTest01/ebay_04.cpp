#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int n = 4;
int m = 4;
int p = 3;
int left_n, left_m;
int right_n, right_m;

vector<pair<int, int>>boat;
queue<pair<int, int>>q;
void bfs() {
	int level = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int y = q.front().first, x = q.front().second; q.pop();
			for (int i = 0; i < (int)boat.size(); i++) {

			}
		}
	}
}

int solution(int n, int m, int p) {
	int answer = 0;
	left_n = n;
	left_m = m;
	int left = left_n + left_m;
	int rifht = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j == 0)continue;
			int nm = i + j;
			if (nm > p)continue;
			boat.push_back({ i,j });
			q.push({ i,j });
		}
	}
	bfs();

	return answer;
}

int main() {
	init();
	solution(n, m, p);

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}