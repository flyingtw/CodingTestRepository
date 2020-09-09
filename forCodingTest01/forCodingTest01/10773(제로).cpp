#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int K;
int ret = 0;
stack<int>q;

void fc1(int a) {
	if (a == 0) {
		q.pop();
	}
	else {
		q.push(a);
	}
}


int main() {
	init();

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		fc1(a);
	}
	while (!q.empty()) {
		ret += q.top();
		q.pop();
	}
	cout << ret;

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}