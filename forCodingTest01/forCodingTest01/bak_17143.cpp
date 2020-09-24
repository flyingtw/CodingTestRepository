#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int arr[101][101];
int N, M, S;




// 1. 낚시왕 오른쪽으로 한칸 이동
// 2. 낚시왕과 가장 가까운 상어중 땅에 가까운 상어 잡기
// -> 상어 사라짐
// 3. 상어 이동

// 한칸에 두마리 상어 있으면 큰놈이 다 먹음


// 1북  2남  3동  4서

// [상어]
// y x 속력 방향 크기


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
	// arr 배열에는 상어번호가 들어가있음 (1번부터)

	for (int i = 0; i < N; i++) {
		if (arr[i][x] != 0) {
			
			int shark_num = arr[i][x]-1;
			ret+=v[shark_num].second.size;
			arr[i][x] = 0;


			// v에서 shark_num 인덱스 샤크 지워주기
			v.erase(v.begin() + shark_num);

			
			return;
		}
	}
}

void moving() {
	// 0. 큐에 남은 상어들 넣어주기
	for (int i = 0; i < (int)v.size(); i++) {
		q.push(v[i].second);
	}
	v.clear();



	// 1. 큐에 있는 상어들 이동시키기
		// 방향전환까지 생각
	// 2. 겹쳐져 있는 상어들중 큰놈만 남기기
	while (!q.empty()) {
		int cy, cx, cspeed, cdir, csize;
		cy = q.front().y;
		cx = q.front().x;
		cspeed = q.front().speed;
		cdir = q.front().dir;
		csize = q.front().speed;
		q.pop();
		

		// 이동
		//	이동 tmp에 아무것도 없으면 낙인
		//		 tmp에 뭐가 있으면 큰것만




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
		// 낚시꾼 상어 잡기
		fishing(i);
		print();
		cout << "-----------" << endl;

		// 상어 이동 하기
		moving();

	}
	
	

	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}