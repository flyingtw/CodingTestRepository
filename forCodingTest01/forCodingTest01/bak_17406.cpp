#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M, K;
int arr[55][55];
int arr2[6][3];
bool check[6];
vector<int>v2;

int tmp[55][55];
int arr3[55][55];


int ret1;
int ret2=1e9;
int ret3=1e9;

void print() {
	cout << "-------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << tmp[i][j] << " ";
		}
	}
	cout << endl;
}


void copy_arr(int back_up[55][55], int origin[55][55]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			back_up[i][j] = origin[i][j];
		}
	}
}

void rotate_arr() {
	
	copy_arr(arr3, arr);
	copy_arr(tmp,arr);
	//cout << "회전" << endl;

	// tmp arr 회전시키기

	for (int i = 0; i < K; i++) {
		//cout << i << "번째 회전" << endl;
		int y = arr2[v2[i]][0]-1;
		int x = arr2[v2[i]][1]-1;
		int s = arr2[v2[i]][2];
		//cout << y << " " << x << " " << s << " " << endl;
		for (int j = s; j > 0; j--) {
			for (int a = x - j + 1; a <= x + j; a++) {//1
				tmp[y - j][a] = arr3[y - j][a - 1];
			}
			for (int a = y - j + 1; a <= y + j; a++) {//2
				tmp[a][x + j] = arr3[a - 1][x + j];
			}
			for (int a = x - j; a <= x + j - 1; a++) {//3
				tmp[y + j][a] = arr3[y + j][a + 1];
			}
			for (int a = y - j; a <= y + j - 1; a++) {//4
				tmp[a][x - j] = arr3[a + 1][x - j];
			}
		}
		copy_arr(arr3, tmp);
		//print();
		
	}
	for (int i = 0; i < N; i++) {
		ret1 = 0;
		for (int j = 0; j < M; j++) {
			ret1 += arr3[i][j];
		}
		ret2 = min(ret2, ret1);
	}
	ret3 = min(ret3, ret2);
	
	


}


void dfs() {
	if ((int)v2.size() == K) {
		// 2. v2 순서대로 연산하기
		rotate_arr();

		/*for (auto it : v2) {
			cout << it << " ";
		}
		cout << endl;*/
		return;
	}
	for (int i = 0; i < K; i++) {
		if (check[i] == false) {
			check[i] = true;
			v2.push_back(i);
			dfs();
			v2.pop_back();
			check[i] = false;
		}
	}

}

int main() {
	init();
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			int b; cin >> b;
			arr2[i][j] = b;
		}
	}
	// 1. K개 모든 순서 정하기
	dfs();
	cout << ret3;


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}