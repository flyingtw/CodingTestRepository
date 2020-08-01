#include <bits/stdc++.h>

using namespace std;

string n1;
vector<int>v;



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
int main() {
	do {
		cin >> n1;
		if (isdigit(atoi(n1.c_str())) || atoi(n1.c_str())>45 || atoi(n1.c_str()) <=0) {
			cout << "false";
			exit(0);
		}
		else {
			v.push_back(stoi(n1));
		}

	} while (getc(stdin) == ' ');

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()),v.end());
	
	if (v.size() != 6) {
		cout << "false";
		exit(0);
	}

	cout << "true";

	



	return 0;
}