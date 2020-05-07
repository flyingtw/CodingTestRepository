#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int>atoz(26,0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a')atoz[0] += 1;
		if (s[i] == 'b')atoz[1] += 1;
		if (s[i] == 'c')atoz[2] += 1;
		if (s[i] == 'd')atoz[3] += 1;
		if (s[i] == 'e')atoz[4] += 1;
		if (s[i] == 'f')atoz[5] += 1;
		if (s[i] == 'g')atoz[6] += 1;
		if (s[i] == 'h')atoz[7] += 1;
		if (s[i] == 'i')atoz[8] += 1;
		if (s[i] == 'j')atoz[9] += 1;
		if (s[i] == 'k')atoz[10] += 1;
		if (s[i] == 'l')atoz[11] += 1;
		if (s[i] == 'm')atoz[12] += 1;
		if (s[i] == 'n')atoz[13] += 1;
		if (s[i] == 'o')atoz[14] += 1;
		if (s[i] == 'p')atoz[15] += 1;
		if (s[i] == 'q')atoz[16] += 1;
		if (s[i] == 'r')atoz[17] += 1;
		if (s[i] == 's')atoz[18] += 1;
		if (s[i] == 't')atoz[19] += 1;
		if (s[i] == 'u')atoz[20] += 1;
		if (s[i] == 'v')atoz[21] += 1;
		if (s[i] == 'w')atoz[22] += 1;
		if (s[i] == 'x')atoz[23] += 1;
		if (s[i] == 'y')atoz[24] += 1;
		if (s[i] == 'z')atoz[25] += 1;
	}
	for (int i = 0; i < atoz.size(); i++) {
		cout << atoz[i] << " ";
	}

	return 0;
}
