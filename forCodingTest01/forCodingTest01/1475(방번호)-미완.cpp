#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

vector<int>plusCard(vector<int> card) {
	vector<int>card = card;
	for (int i = 0; i < card.size(); i++) {
		card[i] += 1;
	}
	return card;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	
	string s;
	cin >> s;
	
	vector<int>card(10, 1);
	vector<bool>status(10, 0);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			if (status[6] != true) {
				status[6] = true;
			}
			else if (status[9] != true) {//6 또는 9 인데 6이 true 이고 9가 false이면
				status[9] == true;
			}
			else {//6 또는 9인데 6이 true 이고 9도 true일때
				card = plusCard(card);//card +1
				
			}
		}
		else {
			if (status[int(s[i] - '0')] == true) {
				card = plusCard(card);
				status[int(s[i] - '0')] = true;
			}
			else {
				status[int(s[i] - '0')] = true;
			}
			
		}
	}
	
	/*
	char a = '0';
	cout << int(a-'0') << endl;
	
	vector<bool>test(10);
	cout << test[0] << endl;
	
	vector<int>test01 = { 1,2,3 };
	test01[1] += 1;
	cout << test01[1] << endl;
	*/

	return 0;
}
