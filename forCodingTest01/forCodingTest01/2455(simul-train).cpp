#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int people_num = 0;
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int out = 0;
		int in = 0;
		cin >> out >> in;
		people_num -= out;
		people_num += in;
		result = max(people_num, result);
	}
	cout << result;

	return 0;
}