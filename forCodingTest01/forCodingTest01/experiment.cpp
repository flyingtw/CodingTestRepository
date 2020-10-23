#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N;
int arr[11][11];
bool visited[11][11];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int>v;
int ret = 0;

void bfs(int y, int x) {
	int cnt = 1;
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int cur_y, cur_x;
		tie(cur_y, cur_x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (arr[ny][nx] == 1 && visited[ny][nx] == false) {
				cnt++;
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
	v.push_back(cnt);

}



void solution(int sizeOfMatrix, int** matrix) {
	N = sizeOfMatrix;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				ret++;
				bfs(i, j);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ret << endl;
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " ";
	}



}

struct input_data {
	int sizeOfMatrix;
	int** matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int* [inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}