#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool visited[25][25];

vector<vector<int>> board = { {0, 0, 0, 0, 0, 0, 0, 1},
							{0, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 1, 0, 0},
							{0, 0, 0, 0, 1, 0, 0, 0},
							{0, 0, 0, 1, 0, 0, 0, 1},
							{0, 0, 1, 0, 0, 0, 1, 0},
							{0, 1, 0, 0, 0, 1, 0, 0},
							{1, 0, 0, 0, 0, 0, 0, 0} };





int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };






//void num_bfs(int i, int j,int N) {
//	
//	queue<pair<int, int>> q;
//
//	//큐에다가 i,j 를 넣기 (bfs 돌릴 섬 좌표)
//	q.push(make_pair(i, j));
//	visited[i][j] = true;// 방문했음
//	
//
//
//	// 맨 처음 섬의 좌표 큐에넣고 상하좌우 체크할때까지(큐가 빌때까지) 섬 바꾸기
//	while (!q.empty()) {
//		int tx = q.front().first; //맨처음 섬의 x 좌표
//		int ty = q.front().second;
//		q.pop(); // 맨처음 섬좌표 구했으니 큐에서 빼주기
//
//		for (int i = 0; i < 4; i++) {//상하좌우 체크
//			int nx = tx + dx[i];
//			int ny = ty + dy[i];
//
//			// 만약 지도 좌표 넘어가면 무시하고 다음 진행
//			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//
//			// 상하좌우 섬이 그대로 1이고 방문하지 않았다면(false)
//			if (board[nx][ny] == 0 && visited[nx][ny] == false) {
//				q.push(make_pair(nx, ny));//큐에 넣어주기
//				
//			}
//		}
//	}
//}
//
//int solution(vector<vector<int>> board) {
//	int answer = 0;
//	int N = board.size();
//	
//
//	num_bfs(0,0, N);
//
//	return answer;
//}
//
//int main() {
//	cin.tie(NULL);
//	cout.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	solution(board);
//
//
//
//
//	return 0;
//}

int solution(vector<vector<int>> board) {
	int answer = 0;


	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	solution(board);




	return 0;
}