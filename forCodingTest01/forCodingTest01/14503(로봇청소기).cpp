#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
int y, x, dir;

// û�ұ�� �ٶ󺸴� ������ �ִ�.
// ��, ��, ��, �� 

// 1. ���� ��ġ û��
// 2. ���翡�� ���� �������� ���ʹ������� ���ʴ�� Ž��
//  a. ���� ���⿡ û�� ���ߴٸ� ȸ�� �� �� ��ĭ ���� -> 1
//  b. ���� û�� �ߴٸ� -> �� �������� ȸ�� -> 2
//  c. �� ���� ��� û�� �Ǿ��ְų� ��
	// -> ��������, ��ĭ ����
//  d. 4���� û�� �Ǵ� ��, ���� ���̶� ���� ���ϴ°�� �۵� stop

// -> �κ� û�ұⰡ û���� ĭ�� ��ĭ�ΰ�?

// 0��, 1��, 2��, 3��
// 3��  0��  1��  2��

// 2��  3��  0��  1��

int arr[51][51];
int cnt = 0;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << "----------------" << endl;
}

void clean(int y, int x,int dir) {
	cnt++;

	arr[y][x] = -1;
	//print();

	//cout << "(" << y << ", " << x << ")" << endl;


	// ���� �� ���� �ֳ�?
	// �ִ�. -> clean(��ǥ, ����)
	// ����. -> 
	int new_dir;
	if (dir == 0)new_dir = 3;
	else new_dir = dir - 1;
	new_dir--;
	for (int i = 0; i < 4; i++) {
		new_dir += 1;
		if (new_dir > 3)new_dir -= 4;
		
		int ny = y + dy[new_dir];
		int nx = x + dx[new_dir];

		if (arr[ny][nx] == 0) {
			clean(ny, nx, new_dir);
			//cout << "2" << endl;
			return;
		}
		//cout << "i :" << i;
		//cout << "3" << endl;

		if (i == 3) {
			//cout << "1" << endl;
			// ��� ������ û�Ұ� �� ��� 
			
			// 0��, 1��, 2��, 3��
			// 3��  0��  1��  2��
			int origin_dir = dir;

			// 2��  3��  0��  1��
			if (dir < 2) {
				dir += 2;
			}
			else {
				dir -= 2;
			}

			if (arr[y + dy[dir]][x + dx[dir]] != 1 ) {
				//cout << y  << " " << x  << endl;
				//cout << "dir :" << dir << endl;
				//cout << y + dy[dir] << " " << x + dx[dir] << endl;
				clean(y + dy[dir], x + dx[dir], origin_dir);
				return;
			}
			else {
				//cout << "û�� ��!" << endl;
				return;
			}

			
			



		}
	}





	


}


int main() {
	init();
	int ret = 0;
	
	cin >> N >> M;
	cin >> y >> x >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	clean(y, x, dir);
	//cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == -1) {
				ret++;
			}
		}
	}
	//print();
	/*if (ret == 1) {
		cout << 1;
	}
	else {
		cout<<ret+1;
	}*/
	cout << ret << endl;
	//print();

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}