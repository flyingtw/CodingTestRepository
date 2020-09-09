#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;

priority_queue<int,vector<int>,greater<int>>pq;
vector<int>v;


void fc(int a) {
	if (a == 0) {
		if (pq.empty()) {//비어있으면
			v.push_back(0);
		}
		else {
			v.push_back(pq.top());
			pq.pop();
		}
	}
	else {
		pq.push(a);
	}
}

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		fc(a);
	}
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << endl;
	}

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}