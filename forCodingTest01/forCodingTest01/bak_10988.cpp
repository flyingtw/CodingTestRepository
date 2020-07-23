#include <iostream>


#define endl "\n"

using namespace std;
string s1;
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


int main() {
	init();

	cin >> s1;
	int word_len = s1.length();
	int mid = word_len / 2;
	bool flag = true;

	for (int i = 0; i < mid; i++) {
		if (s1[i] == s1[word_len - 1]) { 
			word_len--;
			continue; 
		}
		else {
			flag = false;
			break;
		}
			
	}
	if (flag == true)cout << 1 << endl;
	else cout << 0 << endl;

	return 0;
}