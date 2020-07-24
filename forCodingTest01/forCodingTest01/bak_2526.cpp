#include<bits/stdc++.h>
#define endl "\n"



using namespace std;

int N, P;
vector<pair<int,int>>v1;

int cnt = 0;
int idx = -1;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

int fc1(int num) {
	int result;
	result = (num * N) % P;
	return result;
}

bool check(int num) {
	bool flag = false;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].first==num) {
			idx = i;
			return true;
		}

	}
	return false;
}

// 너무 복잡하게 풀었나..?
int main() {
	init();
	cin >> N >> P;
	int n = N;
	v1.push_back(make_pair(n, 0));
	while (true){
		n = fc1(n);
		if (check(n) == false) {
			v1.push_back(make_pair(n, 0));
		}
		else {
			if (v1[idx].second != 2) {
				v1[idx].second += 1;
			}
			else {
				break;
			}
		}

	}
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].second > 0) {
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}
