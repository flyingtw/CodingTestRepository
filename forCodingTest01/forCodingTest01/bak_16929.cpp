#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();
void print();

int N, M;
char arr[51][51];
bool visited[51][51];
int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };


int dfs(int y, int x) {

}


int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}


	







	return 0;
}


void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}