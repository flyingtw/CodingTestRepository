#include <bits/stdc++.h>

using namespace std;




int main() {
	
	char s1[101];
	cin >> s1;
	for (int i = 0; i < 101; i++) {
		if ((s1[i]>=65 && s1[i]<=90) || (s1[i]>=97 && s1[i]<=122)) {
			cout<<s1[i];

		}
		else if (s1[i] == 64) {
			cout << " ";
		}
		else {
			cout<<s1[i];
		}
		
	}


	return 0;
}