#include <iostream>[
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;
vector<vector<int> > maps1 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
vector<vector<int> > maps = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0},{0, 0, 0, 0, 1 }};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[100][100] = { false, };


//void DFS(int x,int y,int N,int M, vector<vector<int> > maps) {
//    cnt++;
//    for (int i = 0; i < 4; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
//        if (maps[nx][ny] == 0 || visited[nx][ny]==true)continue;
//
//        visited[nx][ny] = true;
//        DFS(nx, ny,N,M,maps);
//    }
//}



int solution(vector<vector<int> > maps){
    int answer = 0;
    int N = maps.size();
    int M = maps[0].size();

    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(0, 0), 1));

    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int cnt = Q.front().second;
        Q.pop();

        if (x == N - 1 && y == M - 1) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (visited[nx][ny] == false && maps[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), cnt + 1));
                }
            }
        }
    }
    return -1;
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