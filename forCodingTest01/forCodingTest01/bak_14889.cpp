#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N;
int arr[25][25];

int mid;
vector<int>v;
vector<int>v2;
bool visited[25];
int ret = 1e9;

void true_point() {
	int point1 = 0;
	int point2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] == true && visited[j]==true && i != j) {
				//cout << "i : " << i << " j : " << j << endl;
				point1 += arr[i][j];
			}
			else if (visited[i] == false && visited[j] == false && i != j) {
				point2 += arr[i][j];
			}
		}
	}
	//cout << "점수1 :"<<point1 << endl;
	//cout << "점수2 :" << point2 << endl;
	ret = min(ret,abs(point1 - point2));



}

void dfs(int idx) {
	//cout << "idx :" << idx << endl;
	if ((int)v2.size() == mid) {
		//cout << "v2 size : " << v2.size() << endl;
		/*for (auto it : v2) {
			cout << it << " ";
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			cout << visited[i] << " ";
		}*/

		//visited true인거 2명씩 골라서 점수도출
		true_point();
		//visited false인거 2명씩 골라서 점수도출
		//cout << endl;

		
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			v2.push_back(i);
			dfs(i + 1);
			visited[i] = false;
			v2.pop_back();

		}
		else {
			continue;
		}

	}


}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		v.push_back(i+1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	mid = N / 2;
	dfs(0);

	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}