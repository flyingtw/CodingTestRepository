#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<int>v,v2,v3;
bool check[10001];

// 순열
// 순서 살리면서 뽑는것 (1,3 =/= 3,1)
// permu 함수에 인자 없이 넣어준다.

void permu() {
	if ((int)v2.size() == M) {
		for (auto it : v2) {
			printf("%d ", v[it]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			check[i] = true;
			v2.push_back(i);
			permu();
			check[i] = false;
			v2.pop_back();
		}
	}



}

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


//조합 
// 순서 없이 뽑는거
// 인자를 넣어준다.
void combi(int here) {
	if ((int)v3.size() == M) {
		for (auto it : v3) printf("%d ", v[it]);
		printf("\n");
		return;
	}
	for (int i = here + 1; i < N; i++) {
		v3.push_back(i);
		combi(i);
		v3.pop_back();
	}
}



int main() {
	init();
	cin >> N >> M;
	//scanf_s("%d%d", &N, &M); 
	// 백준에서 scanf_s는 안먹히는 모양
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	permu();
	



	return 0;
}