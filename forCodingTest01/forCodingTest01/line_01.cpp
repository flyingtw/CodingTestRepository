#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


vector<vector<int>> boxes2 = { {1, 2},{2, 1},{3, 3},{4, 5},{5, 6},{7, 8} };
vector<vector<int>> boxes3 = { {1, 2},{3,4},{5,6} };
vector<vector<int>> boxes = { {1, 2},{2, 3},{3, 1} };

int check[1000000];

int solution(vector<vector<int>> boxes) {
	int answer = -1;
	int n = (int)boxes.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			check[boxes[i][j]]++;
		}
	}
	int odd = 0;
	int even = 0;
	for (int i = 0; i < 100001; i++) {
		if (check[i] > 0) {
			if (check[i] % 2 == 1) {
				odd++;
			}
			else {
				even++;
			}
		}	
	}
	answer = n - even;



	return answer;
}

int main() {
	init();
	solution(boxes);


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}