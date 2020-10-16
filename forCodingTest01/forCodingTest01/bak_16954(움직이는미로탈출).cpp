#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

char arr[8][8];
bool visited[8][8];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

int ret;

void print() {
	cout << "-----------------" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;
}

// ���ʾƷ����� �������� -> ���� ������ ������ �Ʒ���
// ���� ������ �Ʒ��� -> �Ʒ����� ���� ��ĭ��
// 7,7 �������� = 1, �Ұ��� = 0
// (1�ʵ���) ���� �����̱� -> �������̱�
void move_arr() {
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	for (int j = 0; j < 8; j++) {
		arr[7][j] = '.';
	}
	print();
}


bool bfs(int y, int x) {
	queue<pair<int, int>>q;
	visited[y][x] = true;
	q.push({ y,x });
	while (!q.empty()) {
		int q_size = q.size();
		while (q_size--) {
			int cur_y = q.front().first;
			int cur_x = q.front().second;
			if (cur_y == 7 && cur_x == 7)return true;
			q.pop();
			
			for (int i = 0; i < 4; i++) {
				int ny = cur_y + dy[i];
				int nx = cur_x + dx[i];
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)continue;
				if (arr[ny][nx] == '.' && visited[ny][nx] == false) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
		//�� ������ -> �������ֱ�
		move_arr();
		
	}
	return false;
}


int main() {
	init();
	
	for (int i = 7; i >=0; i--) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = s[j];
		}
	}
	print();

	if (arr[0][0] == '.') {
		cout << bfs(0, 0);
	}
	else {
		cout << 0;
	}
	

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}