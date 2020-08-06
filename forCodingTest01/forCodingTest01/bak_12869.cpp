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
		while (size--) {// �õ� Ƚ���� ���� q �� ó��
			int cur_x = q.front().a;
			int cur_y = q.front().b;
			int cur_z = q.front().c;
			q.pop();
			if (cur_x == 0 && cur_y == 0 && cur_z == 0) return level; // ������ 0�� �Ǹ� return
			for (int i = 0; i < 6; i++) {
				int nx = max(0,cur_x-dm[i][0]);// 0���� ������ 0���� �ٲ��ֱ�
				int ny = max(0,cur_y-dm[i][1]);
				int nz = max(0,cur_z-dm[i][2]);
				if (visited[nx][ny][nz] == false) {
					visited[nx][ny][nz] = true;
					q.push({ nx,ny,nz });
				}
			}
		}
		level++;// ���� Ƚ��(��)�� ������ ������ ++ ���ش�.
	}
	return -1;// ��������
}




int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		int imsi; cin >> imsi;
		arr[i] = imsi;
	}
	
	//3 struct �� ���� �־��. �� ���ڸ� visited ��ü�� �����
	cout<<bfs(arr[0], arr[1], arr[2]);

	return 0;
}



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
