#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, M;
vector<int>v;
vector<int>v2;
bool check[10001];
int pre = -1;

void permu() {                 // ¼ø¿­ ( 1,7 !=7,1)
    if ((int)v2.size() == M) {
        for (auto it : v2) printf("%d ", v[it]);
        printf("\n");
        return;
    }
    for (int i = 0; i <N; i++) {
        if (!check[i] && pre!=v[i]) {
            pre = v[i];
            check[i] = true;
            v2.push_back(i);
            permu();
            check[i] = false;
            v2.pop_back();
        }
    }
}

int main() {
	init();
	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    permu();
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}