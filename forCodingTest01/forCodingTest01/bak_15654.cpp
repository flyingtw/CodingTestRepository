#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<int>v,v2,v3;
bool check[10001];

// ����
// ���� �츮�鼭 �̴°� (1,3 =/= 3,1)
// permu �Լ��� ���� ���� �־��ش�.

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


//���� 
// ���� ���� �̴°�
// ���ڸ� �־��ش�.
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
	// ���ؿ��� scanf_s�� �ȸ����� ���
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	permu();
	



	return 0;
}