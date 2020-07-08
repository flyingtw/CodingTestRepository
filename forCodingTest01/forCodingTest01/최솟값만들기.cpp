#include <iostream>
#include <vector>
#include<algorithm>

#define endl "\n"

using namespace std;
vector<int> A = {4,2,5,2,3,3,5,6,1,23,1,5};
vector<int> B = { 9,8,7,6,8,5,4,7,45,7,4,6};
bool myfunction(int i, int j) { return (i > j); }


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), myfunction);
    for (int i = 0; i < B.size(); i++) {
        answer += A[i] * B[i];
    }
    




    return answer;
}


int main() {
    cout << __TIMESTAMP__ << endl;
    cout << solution(A, B) << endl;
    cout << __TIMESTAMP__ << endl;

	return 0;
}