#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


// ���ĭ�� ����� 5�� �ִ�.
// ������ ���� �ڽ��� ���̸�ŭ ����� �԰� ���̸� 1 ��´�.
// ������ ������ ������ �ִ� ĭ�� ��и� ���� �� �ִ�.
// �������� ������ �ִٸ� ���̰� � �������� ����� �Դ´�.
// ���� ������ �䱸 ����� ���ٸ� ��� ������ �״´�.

// �������� ���� ���� ������ ������� ���ϰ� �ȴ�.
// (�������� ����)/2 ���� ������ �ִ� ĭ�� ��п� �߰��ȴ�.
// �Ҽ��� �Ʒ��� ������.

// �������� ������ �����Ѵ�.
// �����ϴ� ������ ���̴� 5�� ������� �Ѵ�.
// ������ 8ĭ�� ���̰� 1�� ������ �����.
// ���� ����� ������ ������ �ʴ´�.

// �ܿ￡�� �κ��� ����� ���� �߰��Ѵ�.
// arr[i][j] ��ŭ �߰��ȴ�.

// K ���� ������ ����ִ� ������ ������?


int N, M, K;
int robot[11][11];
int arr[11][11];

int dy[8] = { -1,1,0,0,-1,1 ,-1,1 };
int dx[8] = { 0,0,-1,1,-1,1,1,-1 };


struct Tree {
	int y;
	int x;
	int age;
	bool operator <(Tree tr) {
		return this->age < tr.age;
	}
};

Tree trees[101];
vector<Tree>v;
queue<Tree>q;
queue<Tree>dead;
queue<Tree>live;

void spring() {
	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_age = q.front().age;
		q.pop();

		if (arr[cur_y][cur_x] >= cur_age) {//��� �Ա�, 1�� �Ա�
			arr[cur_y][cur_x] -= cur_age;
			live.push({ cur_y,cur_x,cur_age + 1 });
		}
		else {// �ױ�
			dead.push({ cur_y,cur_x,cur_age });
		}
	}
//	cout << "1" << endl;

}
void summer() {
	while (!dead.empty()) {
		int cur_y = dead.front().y;
		int cur_x = dead.front().x;
		int yang = dead.front().age/2;
		dead.pop();
		arr[cur_y][cur_x] += yang;

	}
	//cout << "2" << endl;

}
void autumn() {
	v.clear();
	//cout << "v�� ������ :" << v.size() << endl;
	//cout << "3-1" << endl;
	while (!live.empty()) {
		int cur_y = live.front().y;
		int cur_x = live.front().x;
		int cur_age = live.front().age;
		
		live.pop();
		if (cur_age % 5 == 0) {
			v.push_back({ cur_y,cur_x,cur_age });
			for (int i = 0; i < 8; i++) {
				//cout << "���س��� :(" << cur_y << ", " << cur_x << ")" << endl;
				int ny = cur_y + dy[i];
				int nx = cur_x + dx[i];
				//cout << dy[i] << " " << dx[i] << endl;
				//cout << "�ֺ����� :(" << ny << ", " << nx << ")" << endl;
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				else { 
					v.push_back({ ny,nx,1 });
				}
			}
		}
		else {
			v.push_back({ cur_y,cur_x,cur_age });
		}

	}
	//cout << "v�� ������ :" << v.size() << endl;
	sort(v.begin(), v.end());
	/*for (int i = 0; i < (int)v.size(); i++) {
		q.push({ v[i].y,v[i].x,v[i].age });
	}*/
	//cout << "3" << endl;
}
void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] += robot[i][j];
		}
	}
}

//void print(int year) {
//	
//	cout <<year<<"��-----------�� ��Ȳ---------" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << endl;
//		for (int j = 0; j < N; j++) {
//			cout << arr[i][j] << " ";
//		}
//	}
//	cout << endl;
//	cout << year << "��-----------���� ��Ȳ---------" << endl;
//	for (int i = 0; i < (int)v.size(); i++) {
//		cout << i << "�� ���� (" << v[i].y << ", " << v[i].x << ")" << endl;
//		cout << "���� :" << v[i].age << endl;
//	}
//
//	/*for (int i = 0; i < M; i++) {
//		cout << i << "�� ���� (" << trees[i].x << ", " << trees[i].y << ")" << endl;
//		cout <<"���� :"<< trees[i].age << endl;
//	}*/
//
//	cout << "-------------------------------" << endl;
//}




int main() {
	init();
	
	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 5;
			cin >> robot[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int y,x, age;
		cin >>y>>x >> age;
		//q.push({ x, y, age });
		v.push_back({ y-1,x-1,age });
		//cin >> trees[i].x >> trees[i].y >> trees[i].age;
	}
	sort(v.begin(), v.end());
	

	for (int i = 0; i < K; i++) {

		//print(i);
		for (int j = 0; j < (int)v.size(); j++) {
			q.push(v[j]);
		}

		spring();
		summer();
		autumn();
		winter();

		//print(i);
	}
	cout << v.size();
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i].y << " " << v[i].x << " " << v[i].age << endl;
	}*/
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}