#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
char arr[1501][1501];
bool visited[1501][1501];

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void bfs(int y, int x) {

}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '.') {
				bfs(i, j);
			}
		}
	}


	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);





}