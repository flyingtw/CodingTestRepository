#include <bits/stdc++.h>
using namespace std;

int n1,n2;
vector<int>v1;
vector<int>v2;
vector<int>result;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
int main() {
	
	do {
		cin >> n1;
		v1.push_back(n1);
	} while (getc(stdin) == ' ');
	do {
		cin >> n2;
		v2.push_back(n2);
	} while (getc(stdin) == ' ');
	
	int L = v1.size();
	int d = 0;
	for (int i = 0; i < L; i++) {
		int money = v1[i] - v2[i];
		if (money >= 0) {
			if (d == 0) {
				result.push_back(money);
			}
			else {
				if (d > money) {
					d -= money;
					result.push_back(0);
				}
				else {
					result.push_back(money - d);
					d = 0;
				}

			}
		}
		else {
			result.push_back(0);
			d += (-money);
		}

		
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}


	return 0;
}