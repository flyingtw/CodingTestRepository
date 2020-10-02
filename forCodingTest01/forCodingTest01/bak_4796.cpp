#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int L, P, V;

int main() {
	init();
	int num=1;
	while (1) {
		cin >> L >> P >> V;
		int ret = 0;
		if (L == 0 && P == 0 && V == 0)break;
		ret += (V / P) * L;
		if (V % P > L) {
			ret += L;
		}
		else {
			ret += V % P;
		}
		cout << "Case " << num << ": " << ret << endl;
		num++;
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}