#include <iostream>
#include <vector>
using namespace std;



vector<vector<int> > v = { {1, 4}, {3, 4}, {3, 10} };

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans(2, 0);

    ans[0] = v[0][0] ^ v[1][0] ^ v[2][0];
    ans[1] = v[0][1] ^ v[1][1] ^ v[2][1];


    return ans;
}


int main() {
    solution(v);


    return 0;
}