#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int n;
vector<char>v2;

bool numbers[10];
vector<int>v;

void fc1() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void dfs(int idx) {
	if ((int)v.size() == n + 1) {
		fc1();
	}
	
	
	for (int i = 0; i < 10; i++) {


		if (numbers[i] == false) {
			numbers[i] = true;

			if (v.size() != 0) {
				char cc = v2[idx - 1];
				if (cc == '<') {
					if (v[idx - 1] < i) {
						v.push_back(i);
						dfs(idx + 1);
						v.pop_back();
						numbers[i] = false;
					}
				}
				else if (cc == '>') {
					if (v[idx - 1] > i) {
						v.push_back(i);
						dfs(idx + 1);
						v.pop_back();
						numbers[i] = false;
					}
				}
			}
			else {
				v.push_back(i);
				dfs(idx + 1);
				v.pop_back();
				numbers[i] = false;
			}
			
			


			
		}
	}
}


int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		v2.push_back(c);
	}




	/*for (int i = 0; i < (int)v2.size(); i++) {
		cout << v2[i] << endl;
	}*/
	dfs(0);


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}