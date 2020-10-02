#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, L;
vector<int>v;
bool visited[1001];
int ret = 0;

int main() {
	init();
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++) {
		if (visited[v[i]] == false) {
			ret++;
			for (int j = v[i]; j < v[i] + L; j++) {
				if (j > 1000)break;
				visited[j] = true;
			}
		}
	}
	cout << ret;


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}