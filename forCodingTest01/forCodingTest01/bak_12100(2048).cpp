#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void init();

int N;
int arr[21][21];
int tmp[21][21];

vector<int>v;

int ret = -987654321;



//5번 상하좌우 이동해서 얻은수 있는 최대
void print() {
	cout << "------------" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
}


void left() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			int target = arr[i][j];
			if (target == arr[i][j + 1]) {
				arr[i][j] = target * 2;
				arr[i][j + 1] = 0;
				j++;
			}
			else {
				continue;
			}
		}
	}
	print();
	bool check = false;
	int y, x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			y = i, x = j;
			if (arr[i][j] == 0){
				if (check == false) {
					y = i; x = j;
					check = true;
					continue;
				}
			}
			else {
				if (check == true) {
					arr[y][x] = arr[i][j];
					arr[i][j] = 0;
					check = false;
					continue;
				}
			}
		}
	}
}



void move() {

	for (auto it : v) {
		cout << it << endl;
		if (it == 1) {// 좌
			for (int i = 0; i < N; i++) {
				bool check = false;
				deque<int>q;
				for (int j = 0; j < N; j++) {
					if (tmp[i][j] != 0) {//0이 아니면 
						if (!q.empty()) {
							if (q.back() == tmp[i][j]) {
								q.pop_back();
								q.push_back(tmp[i][j] * 2);
							}
							else {
								q.push_back(tmp[i][j]);
							}
						}
						else {
							q.push_back(tmp[i][j]);
						}
					}
				}
				check = false;
				int idx = 0;
				while (!q.empty()) {
					tmp[i][idx] = q.front();
					q.pop_front();
					idx++;
				}
				for (int j = idx; j < N; j++) {
					tmp[i][j] = 0;
				}
			 }
			print();
		}
		else if (it == 2) {//우
		
		}
		else if (it == 3) {//상

		}
		else {//하

		}
	}
}

void permu(vector<int>& v) {
	if ((int)v.size() == 3) {
		memcpy(tmp, arr, sizeof(arr));
		move();
		return;
	}

	for (int i = 1; i <= 4; i++) {
		v.push_back(i);
		permu(v);
		v.pop_back();
	}

}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// 1 2 3 4 중복허용 나열
	// 1 1 1 1 1
	// 1 1 1 1 2 이런식으로

	permu(v);
	//left();
	//print();
	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}