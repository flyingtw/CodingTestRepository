#include <iostream>
#include <vector>
#include <algorithm>


#define endl "\n"

using namespace std;

int N, M;

int cards[100];
bool check[100] = { false, };
int num = 0;
int totalSum=0;
//vector<int>totalSum;

// N장의 카드중 3장을 골라 M을 넘지 않으면서 가장 가깝게 만들어야 한다.

void total() {
	int allNum = 0;
	
	for (int i = 0; i < N; i++) {
		//cout << "i :" << i << endl;
		//cout << "check[i] :" << check[i] << endl;
		if (check[i] == true) {
			allNum += cards[i];
		}
		//cout << "---------------" << endl;
	}
	if (allNum <= M) {
		totalSum = max(allNum, totalSum);
	}
}

void sum(int num) {
	if (num==3) {
		total();
		return;
	}
	for (int i = 0; i < N;i++) {
		if (check[i] == false) {
			check[i] = true;
			sum(num + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	sum(0);
	cout << totalSum << endl;



	return 0;
}