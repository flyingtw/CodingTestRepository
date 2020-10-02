#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


// 모든칸에 양분은 5씩 있다.
// 나무는 봄에 자신의 나이만큼 양분을 먹고 나이를 1 얻는다.
// 각각의 나무는 나무가 있는 칸의 양분만 먹을 수 있다.
// 여러개의 나무가 있다면 나이가 어린 나무부터 양분을 먹는다.
// 땅에 나무의 요구 양분이 없다면 즉시 나무는 죽는다.

// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
// (죽은나무 나이)/2 값이 나무가 있던 칸의 양분에 추가된다.
// 소수점 아래는 버린다.

// 가을에는 나무가 번식한다.
// 번식하는 나무의 나이는 5의 배수여야 한다.
// 인접한 8칸에 나이가 1인 나무가 생긴다.
// 땅을 벗어나면 나무는 생기지 않는다.

// 겨울에는 로봇이 양분을 땅에 추가한다.
// arr[i][j] 만큼 추가된다.

// K 년이 지난후 살아있는 나무의 갯수는?


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

		if (arr[cur_y][cur_x] >= cur_age) {//양분 먹기, 1살 먹기
			arr[cur_y][cur_x] -= cur_age;
			live.push({ cur_y,cur_x,cur_age + 1 });
		}
		else {// 죽기
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
	//cout << "v의 사이즈 :" << v.size() << endl;
	//cout << "3-1" << endl;
	while (!live.empty()) {
		int cur_y = live.front().y;
		int cur_x = live.front().x;
		int cur_age = live.front().age;
		
		live.pop();
		if (cur_age % 5 == 0) {
			v.push_back({ cur_y,cur_x,cur_age });
			for (int i = 0; i < 8; i++) {
				//cout << "기준나무 :(" << cur_y << ", " << cur_x << ")" << endl;
				int ny = cur_y + dy[i];
				int nx = cur_x + dx[i];
				//cout << dy[i] << " " << dx[i] << endl;
				//cout << "주변나무 :(" << ny << ", " << nx << ")" << endl;
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
	//cout << "v의 사이즈 :" << v.size() << endl;
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
//	cout <<year<<"년-----------땅 상황---------" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << endl;
//		for (int j = 0; j < N; j++) {
//			cout << arr[i][j] << " ";
//		}
//	}
//	cout << endl;
//	cout << year << "년-----------나무 상황---------" << endl;
//	for (int i = 0; i < (int)v.size(); i++) {
//		cout << i << "번 나무 (" << v[i].y << ", " << v[i].x << ")" << endl;
//		cout << "나이 :" << v[i].age << endl;
//	}
//
//	/*for (int i = 0; i < M; i++) {
//		cout << i << "번 나무 (" << trees[i].x << ", " << trees[i].y << ")" << endl;
//		cout <<"나이 :"<< trees[i].age << endl;
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