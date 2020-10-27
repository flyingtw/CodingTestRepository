#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int popul[11];
vector<int>v[11];
bool visited[11];

vector<int>a;


int arr[11][11];

bool realvisit[11];

int cnt;

bool flag1;
bool flag2;

void init();

bool bfs(int cur) {
	realvisit[cur] = true;
	queue<int>q;
	q.push(cur);

	for (int i = 0; i < v[cur].size(); i++) {
		if (visited[v[cur][i]] == true && realvisit[v[cur][i]] == false) {
			cnt++;
			realvisit[v[cur][i]] = true;
			q.push(v[cur][i]);
		}
	}
	if (cnt != a.size()) {
		return false;
	}
	else {
		return true;
	}
}

void check() {
	memset(realvisit, false, sizeof(realvisit));
	// visited 에서 true 팀, false 팀 나뉘어짐
	
	// 예시
	// true 팀  2 4 5
	// false 팀 0 1 3
	
	for (int i = 0; i < N; i++){
		if (visited[i] == true && realvisit[i]==false) {
			cnt = 1;
			flag1 = bfs(i);
			
		}
	}

}


void permu(int m,int idx) {
	if (a.size() == m) {
		check();
		//체크
		/*for (int i = 0; i < (int)a.size(); i++) {
			cout << a[i] << " ";
		}*/
		for (int i = 0; i < N; i++) {
			if (visited[i] == true) {
				cout << i << " ";
			}
		}
		cout << "-------------" << endl;

		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			a.push_back(i);
			permu(m,i);
			a.pop_back();
			visited[i] = false;

		}
	}

}

int main() {
	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> popul[i];
	}
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			v[i].push_back(b - 1);
			arr[i][b - 1] = 1;
			arr[b - 1][i] = 1;
		}
	}


	//1 5, 2 4, 3 3, 4 2, 5 1
	// 6개중에 1~5개 고르기
	
	// N개중에 1 ~ N/2 +1개 고르기
	// 7개면 1,2,3,4개 개 고르고
	cout << "--arr 배열--" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------" << endl;





	cout << "---" << endl;
	for (int i = 0; i < N; i++) {
		int n = (int)v[i].size();
		cout <<"["<< i << " 번] ";
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "=============" << endl;

	int mid;
	if (N % 2) {
		mid = N / 2 + 1;
	}
	else mid = N / 2;
	

	for (int i = 1; i <= mid; i++) {

		permu(i,0);

	}



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}