#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

vector<int>v;
priority_queue<int>pq;

int main() {
	init();
	
	pq.push(1);
	pq.push(-99);
	pq.push(20);
	pq.push(100);
	pq.push(43);
	cout << pq.top() << endl;
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}