#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


int arr[210][210];
int fare[210][210];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    int n = (int)fares.size();
    int m = (int)fares[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            arr[i][j] = fares[i][2];
            arr[j][i]= fares[i][2];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << endl;
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
    }


    return answer;
}



int main() {
    init();





    return 0;
}
void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}





