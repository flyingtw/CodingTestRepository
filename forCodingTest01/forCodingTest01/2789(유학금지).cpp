#include <iostream>
#include <vector>
#include <string>

using namespace std;
// CAMBRIDGE
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> imsi;

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C' || s[i] == 'A' || s[i] == 'M' || s[i] == 'B' || s[i] == 'R' || s[i] == 'I' || s[i] == 'D' || s[i] == 'G' || s[i] == 'E') {
			imsi.push_back(i);
		}
	}
	int num = imsi.size();
	
	for (int i = 0; i < num;i++) {
		
		s.erase(s.begin() + imsi[num-i-1]);
	}
	cout << s << endl;


	return 0;
}
