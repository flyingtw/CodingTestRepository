#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int su[3];

void init();

int arr[61][61][61];
bool visited[61][61][61];

int dx[6][3] = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9} };

struct p {
	int x, y, z;
};

int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		su[i] = a;
	}
	queue<p>q;
	q.push({});
	//3 struct �� ���� �־��. �� ���ڸ� visited ��ü�� �����
	
	


	
	

	return 0;
}



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
