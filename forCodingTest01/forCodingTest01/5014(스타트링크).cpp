#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define endl "\n"


using namespace std;

// F : 총 높이, S : 강호위치, G : 목적지, U : +, D : -
int F, S, G, U, D;
int visited[1000001];
queue<int>Q;


int BFS() {
	memset(visited, -1, sizeof(visited));
	if (S == G) return 0;
	visited[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur == G)return visited[cur];
		int cur_U = cur + U;
		int cur_D = cur - D;
		if (cur_U <= F && visited[cur_U] == -1) {
			Q.push(cur_U);
			visited[cur_U] = visited[cur] + 1;
		}
		if (cur_D >= 1 && visited[cur_D] == -1) {
			Q.push(cur_D);
			visited[cur_D] = visited[cur] + 1;

		}
		
	}
	
	return -1;



}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> F >> S >> G >> U >> D;
	
	

	int answer = BFS();
	if (answer == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << answer << endl;
	}

	return 0;
}