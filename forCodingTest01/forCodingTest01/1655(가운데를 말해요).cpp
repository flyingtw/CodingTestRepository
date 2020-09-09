#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


int N;

priority_queue<int>min_pq;
priority_queue<int>max_pq;

void speak(int a) {
	

}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		speak(a);
	}
	
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}