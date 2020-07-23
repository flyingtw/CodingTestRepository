#include <iostream>


#define endl "\n"

using namespace std;

string s1;
int arr[30];//default ดย 0


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


int main() {
	init();
	cin >> s1;
	for (int i = 0; i < s1.length(); i++) {
		arr[s1[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}