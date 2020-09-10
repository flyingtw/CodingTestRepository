#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
vector<string>v;
bool visited[30];
int n = 0;

vector<int>v2;

void dfs(int idx) {
	if ((int)v2.size() == n) {

	}

	for (int i = 0; i < n; i++) {
		if(visited[])
	}

}

int main() {
	init();

	cin >> N;

	

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (visited[s[j] - 65] == false) {
				n++;
				visited[s[j] - 65] = true;
			}
		}
		v.push_back(s);
	}

	for (int i = 0; i < 26; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;

	//visited = true 중 9부터 

	// 사용된 알바벳 갯수 = n
	// n개중 n개 순서 있이 나열 -> 


	dfs(0);



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}