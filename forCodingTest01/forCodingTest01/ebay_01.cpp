#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


vector<vector<int>> simulation_data = { {0, 3},{2, 5},{4, 2},{5, 3} };
int N = 2;

bool check[21][500];

void init();
int solution(int N, vector<vector<int>> simulation_data);

int main() {
	init();

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

int solution(int N, vector<vector<int>> simulation_data) {
	int answer = 0;
	int n = (int)simulation_data.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(check[])
		}
	}


	return answer;
}