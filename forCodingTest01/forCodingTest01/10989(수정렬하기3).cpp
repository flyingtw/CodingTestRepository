#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define MAX 10000
using namespace std;

//입력받은 N개의 숫자를 오름차순으로 정렬하기
// 해결 : 계수 정렬임을 이용해 빈도가 얼마나 많이 나왔는지를 세준다.
int N;
int arr[MAX+1] = { 0, };


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}





int main() {
	init();
	
	cin >> N;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i <= MAX; i++) {
		while (arr[i] != 0) {
			cout << i << endl;
			arr[i]--;
		}
	}


	return 0;
}