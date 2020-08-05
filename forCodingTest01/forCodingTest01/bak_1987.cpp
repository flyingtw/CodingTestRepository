#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, M;
char arr[21][21];
bool visited[26];
int bit_visited = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
//vector<char>v;
int answer;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void dfs(int y, int x,int cnt) {
	
	answer = max(answer, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

		//if (!visited[arr[ny][nx]-'A']) {
			/*visited[arr[ny][nx] - 'A'] = true;
			dfs(ny, nx,cnt+1);
			visited[arr[ny][nx] - 'A'] = false;*/
		
			
		// ºñÆ®¸¶½ºÅ· ±â¹ýÀ¸·Î Ç¬°Í.
		if(!(bit_visited & (1 << (arr[ny][nx] - 'A')))) {
			bit_visited = bit_visited | (1 << (arr[ny][nx] - 'A'));
			dfs(ny, nx, cnt + 1);
			bit_visited = bit_visited ^ (1 << (arr[ny][nx] - 'A'));
		}
	}
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
	bit_visited =bit_visited | (1 << (arr[0][0] - 'A'));
	//visited[arr[0][0] - 'A'] = true;
	dfs(0, 0,1);
	cout << answer;
	return 0;
	/*int a = 11;

	if (a & 1 == 1) {
		cout << "È¦¼ö" << endl;
	}
	else {
		cout << "Â¦¼ö" << endl;
	}*/
	/*int a = 100;
	cout << (a | ('C' - 'A')) << endl;
	cout << (a ^ ('C' - 'A')) << endl;
	cout << (a & ('C' - 'A')) << endl;*/

}
