#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


int N;
int ret = 0;

//3, 5ºÀÁö µÎ°³

int main() {
	init();
	
	cin >> N;

	ret += (N / 5);

	N = N - (N / 5) * 5;
	
	cout << N << endl;


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}