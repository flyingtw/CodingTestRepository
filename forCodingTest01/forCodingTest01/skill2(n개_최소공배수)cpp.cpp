#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

vector<int> arr = { 2,6,8,14 };
vector<int> arr2 = { 1,2,3 };
vector<int> arr3 = { 1,17,48 };



// n개의 숫자의 최소공배수 return 하기
// 최소공배수 구하는법 : 두 수 비교해서 작은수를 더해가면서(작은수의 배수) 큰수의 배수 찾으면됨

int findLCM(int a, int b) {
	int smallNum = min(a, b);
	int LCM = smallNum;
	while ((LCM % a != 0) || (LCM % b != 0)) {
		LCM += smallNum;
	}
	return LCM;
}


int solution(vector<int> arr) {
	int answer = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		arr[i + 1] = findLCM(arr[i], arr[i + 1]);
	}
	answer = arr.back();

	return answer;
}



int main() {
	

	cout << solution(arr3) << endl;



	return 0;
}