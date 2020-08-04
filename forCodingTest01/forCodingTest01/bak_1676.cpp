#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

int main() {
	init();
	cin >> N;
	int two = 0;
	int five = 0;
	for (int i = 2; i <= N; i *= 2) {
		two += (N / i);
	}
	for (int i = 5; i <= N; i *= 5) {
		five += (N / i);
	}
	cout << min(two, five);

	return 0;
}
