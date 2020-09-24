#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int arr[101][101];
int N, M, S;




// 1. ���ÿ� ���������� ��ĭ �̵�
// 2. ���ÿհ� ���� ����� ����� ���� ����� ��� ���
// -> ��� �����
// 3. ��� �̵�

// ��ĭ�� �θ��� ��� ������ ū���� �� ����


// 1��  2��  3��  4��

// [���]
// y x �ӷ� ���� ũ��


struct Shark {
	int y;
	int x;
	int speed;
	int dir;
	int size;
};

vector<pair<int,Shark>>v;

queue<Shark>q;


int ret = 0;

void fishing(int x) {
	// arr �迭���� ����ȣ�� ������ (1������)

	for (int i = 0; i < N; i++) {
		if (arr[i][x] != 0) {
			
			int shark_num = arr[i][x]-1;
			ret+=v[shark_num].second.size;
			arr[i][x] = 0;


			// v���� shark_num �ε��� ��ũ �����ֱ�
			v.erase(v.begin() + shark_num);

			
			return;
		}
	}
}

void moving() {
	// 0. ť�� ���� ���� �־��ֱ�
	for (int i = 0; i < (int)v.size(); i++) {
		q.push(v[i].second);
	}
	v.clear();



	// 1. ť�� �ִ� ���� �̵���Ű��
		// ������ȯ���� ����
	// 2. ������ �ִ� ������ ū�� �����
	while (!q.empty()) {
		int cy, cx, cspeed, cdir, csize;
		cy = q.front().y;
		cx = q.front().x;
		cspeed = q.front().speed;
		cdir = q.front().dir;
		csize = q.front().speed;
		q.pop();
		

		// �̵�
		//	�̵� tmp�� �ƹ��͵� ������ ����
		//		 tmp�� ���� ������ ū�͸�




	}



}


void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}



int main() {
	init();
	cin >> N >> M >> S;
	for (int i = 0; i < S; i++) {
		Shark sk;
		cin >> sk.y >> sk.x >>sk.speed>> sk.dir>>sk.size;
		sk.y -= 1;
		sk.x -= 1;
		arr[sk.y][sk.x] = i + 1;
		v.push_back(make_pair(i + 1, sk));
	}
	print();
	cout << "-----------" << endl;
	for (int i = 0; i < M; i++) {
		// ���ò� ��� ���
		fishing(i);
		print();
		cout << "-----------" << endl;

		// ��� �̵� �ϱ�
		moving();

	}
	
	

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}