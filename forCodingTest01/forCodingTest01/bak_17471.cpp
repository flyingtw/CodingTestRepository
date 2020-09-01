#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
vector<int>v;
int arr[11][11];



int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			arr[i][a - 1] = b;
		}
	}

	cout << "-----------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << "-----------------------" << endl;
	//1. N개의 점 중에서 1개, 2개, ... N개 뽑아서 팀을 꾸림
	//2. 연결 유효한지 확인
	//3. 점수 합 구하기


	 


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}