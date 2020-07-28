#include <bits/stdc++.h>

using namespace std;

int N;
int x, y;

vector<pair<int, int>>ppl;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		ppl.push_back({ x,y });
	}
	for (int i = 0; i < N; i++) {
		int num = 1;
		for (int j = 0; j < N; j++) {
			if (ppl[i].first < ppl[j].first && ppl[i].second < ppl[j].second) {
				num++;
			}
		}
		cout << num << " ";
	}





	return 0;
}