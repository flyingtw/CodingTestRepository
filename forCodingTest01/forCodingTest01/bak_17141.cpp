#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();
void print();


int N, M;//M : 바이러스 갯수
char arr[51][51];
int tmp_arr[51][51];
int visited[51][51];


void virus() {
	//memset(visited, 0, sizeof(visited));
	
	//queue<pair<int, int>>q;
	print(); 
	cout << endl;
	cout << "------------------" << endl;
	
}

void plant(int n, int idx) {
	if (n == M) {
		virus();
		return;
	}
	for (int i = idx / N; i < N; i++) {
		for (int j = idx % N; j < N; j++) {
			idx++;
			if (arr[i][j] == '2') {
				arr[i][j] = 0;
				tmp_arr[i][j] = 1;
				cout << "i :" << i << " " << "j :" << j << endl;
				plant(n + 1, idx);
				tmp_arr[i][j] = 0;
				arr[i][j] = '2';
			}
		}
	}

}

int main() {
	init();
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	plant(0);

	//print();

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << tmp_arr[i][j] << " ";
		}
	}
}