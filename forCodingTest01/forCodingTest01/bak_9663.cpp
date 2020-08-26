#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
bool crossB[60];
bool crossT[60];
bool ys[60];


int back_tracking(int y) {
	if (y == N)return 1;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (crossT[y + i] || crossB[y - i + N - 1] || ys[i])continue;
		crossT[y + i] = true;
		crossB[y - i + N - 1] = true;
		ys[i] = true;
		ret += back_tracking(y + 1);
		crossT[y + i] = false;
		crossB[y - i + N - 1] = false;
		ys[i] = false;
	}
	return ret;
}


int main() {
	init();
	cin >> N;
	cout<<back_tracking(0);


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}