#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
vector<int>v;

int ret = 0;

bool visited[201];
bool arr[201][201];

void combi(int idx,int cnt) {
	if (cnt == 3) {
		if (arr[v[0]][v[1]] == false && arr[v[0]][v[2]] == false && arr[v[1]][v[2]] == false) {
			ret++;
		}
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (visited[i] == true)continue;
		visited[i] = true;
		v.push_back(i);
		combi(i, cnt + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int y, x;
		cin >> y >> x;
		arr[y][x] = true;
		arr[x][y] = true;
	}
	combi(1,0);
	cout << ret;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}