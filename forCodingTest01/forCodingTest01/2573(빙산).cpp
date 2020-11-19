#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N, M;
int arr[301][301];
bool visited[301][301];
int tmp[301][301];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int times = 0;

bool flag = false;


void init();

void bfs(int y, int x) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (tmp[ny][nx] != 0 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}

	}
}


int melt() {


	flag = false;
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) continue;
			else {
				flag = true;

				int now = arr[i][j];

				for (int a = 0; a < 4; a++) {
					int ny = i + dy[a];
					int nx = j + dx[a];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
					if (arr[ny][nx] == 0) {//π∞¿Ã∏È ≥Ï¥¬¥Ÿ
						now--;
					}
				}
				if(now>=0) tmp[i][j] = now;
			}
		}
	}
	if (flag == false) {
		return -1;
	}


	/*cout << "≥Ï¿∫ »ƒ ∫˘ªÍ" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------" << endl;*/



	memset(visited, false, sizeof(visited));
	int island = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] != 0 && visited[i][j]==false) {
				island++;
				bfs(i, j);
			}
		}
	}
	memcpy(arr, tmp, sizeof(arr));

	times++;
	//cout << "º∂∞πºˆ: " << island << endl;
	//cout << "Ω√∞£ :" << times << endl;

	return island;


}

int main() {
	init();



	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	//-1 : ≥Ï¿œ∞‘ æ¯¿Ω 
	// º˝¿⁄ : º∂¿« ∞πºˆ

	// 1∞≥ -> ∞Ëº” µπ∏∞¥Ÿ
	// 2∞≥ ¿ÃªÛ -> √ ∞° ¥‰
	while (1) {
		int ans = melt();
		if (ans == 1) {
			continue;
		}
		else if (ans == -1) {
			//cout << "≥Ï¿œ∞‘ æ¯¿Ω (Ω√∞£) : " << times << endl;
			cout << 0;
			break;
		}
		else if (ans == 0) {
			cout << 0;
			break;
		}
		else {
			//cout << "º∂¿Ã 2∞≥ ¿ÃªÛ¿Ã µ  : "<<times << endl;
			cout << times;
			break;
		}

	}
	



	

	



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}