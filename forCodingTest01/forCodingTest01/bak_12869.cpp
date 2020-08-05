#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;

vector<int>v1;
vector<int>v2;
bool check[10005];
void init();


void permu() {
    if ((int)v2.size() == N) {
        for (auto it : v2) printf("%d ", v1[it]);
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check[i]) {
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
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v1.push_back(a);
	}
	
	permu();

	return 0;
}



void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
