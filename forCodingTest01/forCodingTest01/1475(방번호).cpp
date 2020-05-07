#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	
	string s;
	cin >> s;
	
	vector<int>card(10, 1);
	vector<bool>status(10, 0);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			if(status[int(s[i]-'0')]==)
		}
	}
	
	/*
	char a = '0';
	cout << int(a-'0') << endl;
	
	vector<bool>test(10);
	cout << test[0] << endl;
	
	vector<int>test01 = { 1,2,3 };
	test01[1] += 1;
	cout << test01[1] << endl;
	*/

	return 0;
}
