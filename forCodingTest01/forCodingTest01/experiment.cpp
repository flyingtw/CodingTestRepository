#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

vector<int>v;

int main() {
	init();
	int a = 2;
	cout << a + '0' << endl;
	cout << bitset<4>(a);

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}