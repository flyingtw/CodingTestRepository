#include <iostream>[
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;
vector<vector<int> > maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
vector<vector<int> > maps2 = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0},{0, 0, 0, 0, 1 }};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[100][100] = { false, };

int cnt = 0;

void DFS(int x,int y,int N,int M, vector<vector<int> > maps) {
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
        if (maps[nx][ny] == 0 || visited[nx][ny]==true)continue;

        visited[nx][ny] = true;
        DFS(nx, ny,N,M,maps);
    }
}



int solution(vector<vector<int> > maps){
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();

    if (maps[N - 2][M - 2] == 0 && maps[N - 1][M - 2] == 0 && maps[N - 2][M - 1] == 0)return -1;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 1 && visited[i][j]==false) {
                visited[i][j] = true;
                DFS(i, j,N,M,maps);
            }
        }
    }

    answer = cnt;


    return answer;
}

int main() {
    cout<<solution(maps)<<endl;
    for (int i = 0; i < maps.size(); i++) {
        cout << endl;
        for (int j = 0; j < maps[0].size(); j++) {
            cout << maps[i][j] << " ";
        }
    }


	return 0;
}