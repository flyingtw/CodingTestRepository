#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void init();


int main() {
	init();

	
	vector<int>v;
	v.push_back(0);
	v.push_back(1);

	int n;
	cin >> n;
	int cnt =2;
	for (int i = 2; i <= 100000; i++) {
		int tmp = i;
		while (tmp % 2 == 0) {
			tmp /= 2;
		}
		while (tmp % 3 == 0) {
			tmp /= 3;
		}
		while (tmp % 5 == 0) {
			tmp /= 5;
		}
		if (tmp == 1) {
			v.push_back(i);
			if (cnt == n)break;
			else cnt++;
		}
		else continue;

	}
	cout << v[n];
	



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}