#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

string N;
vector<int>numbers(11,0);


/*
다솜이는 은진이의 옆집에 새로 이사왔다.다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.다솜이의 방 번호가 주어졌을 때, 
필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
*/
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	//N = "9999";//2
	cin >> N;
	int num=N.size();
	bool flag = false;
	for (int i = 0; i < num; i++) {
		if (N[i] == '6' || N[i] == '9') {
			if (flag == false) {
				numbers[6]++;
				flag = true;
			}
			else {
				numbers[9]++;
				flag = false;
			}
		}
		else {
			numbers[N[i] - '0']++;
		}
	}
	
	
	cout << *max_element(numbers.begin(), numbers.end()) << endl;
	return 0;
}