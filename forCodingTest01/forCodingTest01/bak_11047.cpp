#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, K;
vector<int>money;

int main() {
	init();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		money.push_back(a);
	}

	sort(money.begin(), money.end(), greater<>());

	int coin = 0;
	for (int i = 0; i < (int)money.size(); i++) {
		if (money[i] > K)continue;
		else {
			int imsi= K / money[i];
			coin += imsi;
			K = K - (money[i] * imsi);
		}
	}
	cout << coin;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}