#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

vector<int>ppl;
bool check[9] = { false, };
int all = 0;

void total() {
	int allNum = 0;
	for (int i = 0; i < 9; i++) {
		if (check[i] == true) {
			allNum += ppl[i];
		}

	}
	if (allNum == 100) {
		
		for (int i = 0; i < 9; i++) {
			if (check[i] == true) {
				cout << ppl[i] << endl;
			}
		}
		exit(0);
	}
	return;
}

void sum(int num) {
	if (num == 7) {
		total();
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (check[i] == false) {
			check[i] = true;
			sum(num + 1);
			check[i] = false;
		}
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int small;
	for (int i = 0; i < 9; i++) {
		cin >> small;
		ppl.push_back(small);
	}
	sort(ppl.begin(), ppl.end());
	sum(0);






	return 0;
}