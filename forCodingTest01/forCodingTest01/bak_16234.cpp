#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N, L, R;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int arr[101][101];
bool visited[101][101];
int border[101][101];
int cnt = 1;
vector<pair<int, int>>v;
bool open = false;


void init();

void bfs_border(int y, int x) {
	
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	border[y][x] = cnt;
	int cty_num = 1;
	int popul=arr[y][x];
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		
		q.pop();
		int ppl=0;
		

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			

			if (ny < 0 || nx < 0 || ny >= N || nx >= N )continue;
			if (arr[cur_y][cur_x] - arr[ny][nx] <= 0) {
				ppl = arr[ny][nx] - arr[cur_y][cur_x];
			}
			else {
				ppl = arr[cur_y][cur_x] - arr[ny][nx];
			}
			
			if (ppl >= L && ppl <= R && visited[ny][nx]==false) {
				border[ny][nx] = cnt;
				visited[ny][nx] = true;
				q.push({ ny,nx });
				cty_num++;
				popul += arr[ny][nx];
				open = true;
			}
			
		}
	}
	//cout << "cnt :" << cnt << " " << "cty_num :" << cty_num <<" "<<"popul :"<< popul << " changed :"<<popul/cty_num<<endl;
	v.push_back({ cnt,popul / cty_num });
	cnt++;
}





int main() {
	init();
	cin >> N >> L >> R;

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; cin >> a;
			arr[i][j] = a;
		}
	}
	

	int ret = 0;
	while (1) {
		v.clear();
		memset(visited, 0, sizeof(visited));
		memset(border, 0, sizeof(border));
		cnt = 1;
		open = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					bfs_border(i, j);
					
				}
			}
		}
		
		if (open == true) {
			ret++;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = v[border[i][j] - 1].second;
					
				}
			}
		}
		if (open == false)break;
		
		
	}
	cout << ret;

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
