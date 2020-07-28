#include<bits/stdc++.h>

using namespace std;

int main() {
	string s1; getline(cin, s1);
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 65 && s1[i] <= 77 || s1[i] >= 97 && s1[i] <= 109) {
			s1[i] += 13;

		}
		else if (s1[i] >= 78 && s1[i] <= 90 || s1[i] >= 110 && s1[i] <= 122) {
			s1[i] -= 13;
		}
		else continue;
		
	}
	cout << s1;


	return 0;
}