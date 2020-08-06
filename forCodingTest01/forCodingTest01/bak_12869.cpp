#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int arr[3];
bool visited[61][61][61];
int level;

int dm[6][3] = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9} };

struct p {
	int a,b,c;
};


void init();
int bfs(int x, int y, int z) {
	queue<p>q;
	q.push({ x,y,z });
	visited[x][y][z] = true;
	while (!q.empty()) {
		int size = (int)q.size();
		while (size--) {// 시도 횟수가 같은 q 만 처리
			int cur_x = q.front().a;
			int cur_y = q.front().b;
			int cur_z = q.front().c;
			q.pop();
			if (cur_x == 0 && cur_y == 0 && cur_z == 0) return level; // 모든수가 0이 되면 return
			for (int i = 0; i < 6; i++) {
				int nx = max(0,cur_x-dm[i][0]);// 0보다 작을때 0으로 바꿔주기
				int ny = max(0,cur_y-dm[i][1]);
				int nz = max(0,cur_z-dm[i][2]);
				if (visited[nx][ny][nz] == false) {
					visited[nx][ny][nz] = true;
					q.push({ nx,ny,nz });
				}
			}
		}
		level++;// 같은 횟수(층)의 연산이 끝나면 ++ 해준다.
	}
	return -1;// 오류검출
}




int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int imsi; cin >> imsi;
		arr[i] = imsi;
	}
	
	//3 struct 를 만들어서 넣어라. 뺀 숫자를 visited 주체로 만들기
	cout<<bfs(arr[0], arr[1], arr[2]);

	return 0;
}



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
