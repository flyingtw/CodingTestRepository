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
//	//ť���ٰ� i,j �� �ֱ� (bfs ���� �� ��ǥ)
//	q.push(make_pair(i, j));
//	visited[i][j] = true;// �湮����
//	
//
//
//	// �� ó�� ���� ��ǥ ť���ְ� �����¿� üũ�Ҷ�����(ť�� ��������) �� �ٲٱ�
//	while (!q.empty()) {
//		int tx = q.front().first; //��ó�� ���� x ��ǥ
//		int ty = q.front().second;
//		q.pop(); // ��ó�� ����ǥ �������� ť���� ���ֱ�
//
//		for (int i = 0; i < 4; i++) {//�����¿� üũ
//			int nx = tx + dx[i];
//			int ny = ty + dy[i];
//
//			// ���� ���� ��ǥ �Ѿ�� �����ϰ� ���� ����
//			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//
//			// �����¿� ���� �״�� 1�̰� �湮���� �ʾҴٸ�(false)
//			if (board[nx][ny] == 0 && visited[nx][ny] == false) {
//				q.push(make_pair(nx, ny));//ť�� �־��ֱ�
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