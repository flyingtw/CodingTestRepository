#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

struct HORSE {
	int y;
	int x;
	int dir;
};

int N, K;
int arr[15][15];

HORSE horse[11];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };


// -> <- ^ v



int main() {
	init();

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}

	for (int i = 0; i < K; i++) {
		int y, x, dir; cin >> y >> x >> dir;
		horse[i].y = y-1;
		horse[i].x = x-1;
		horse[i].dir = dir-1;

	}

	//  horse[0] ~ horse[K] 까지 이동


	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}