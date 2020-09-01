#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


vector<int> v, v2, v3;
bool check[100001];
int select[100001];



int n = 2;
vector<vector<int>> products = { {10, 3, 2},{15, 2, 5} };//48

//int n = 3;
//vector<vector<int>> products = { {6, 5, 1},{11, 3, 2},{7, 10, 3} };//120


void sum() {
    int money = 0;
    vector<vector<int>> temp = products;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][0]=
        }
    }
    
    


}


void dfs(int cnt) { 
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            v2.push_back(select[i]);
        }
        sum();
        v2.clear();
        return;
        }
    
    for (int i = 0; i < n; i++) { 
        select[cnt] = v[i]; 
        dfs(cnt + 1); 
    } 
}



long long solution(int n, vector<vector<int>> products) {
	long long answer = 0;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    dfs(0);
    //permu();

	return answer;
}

int main() {
	init();
	solution(n, products);
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}