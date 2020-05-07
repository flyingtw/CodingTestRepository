#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string a = "01234567";
	int first = 3;
	int second = 6;
	a.erase(a.begin() + second);
	a.erase(a.begin() + first);
	cout << a << endl;


	return 0;
}
