#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define endl "\n"

using namespace std;

vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
string hand = "right";




string Compare(int num, int left, int right) {
	int ld=0;
	int rd=0;
	string result;
	if (num == 2) {
		if (left == 1 || left == 5) {
			ld = 1;
		}
		else if (left == 4 || left == 8) {
			ld = 2;
		}
		else if (left == 7 || left == 0) {
			ld = 3;
		}
		else if(left==10){
			ld = 4;
		}


		if (right == 3 || right == 5) {
			rd = 1;
		}
		else if (right == 6 || right == 8) {
			rd = 2;
		}
		else if (right == 9 || right == 0) {
			rd = 3;
		}
		else if(right==11){
			rd = 4;
		}
	}
	if (num == 5) {
		if (left == 2 || left == 4 || left == 8) {
			ld = 1;
		}
		else if (left == 1 || left == 7 || left == 0) {
			ld = 2;
		}
		else if (left ==10) {
			ld = 3;
		}


		if (right == 2 || right == 6 || right == 8) {
			rd = 1;
		}
		else if (right == 3 || right == 0 || right == 9) {
			rd = 2;
		}
		else if (right == 11) {
			rd = 3;
		}
		
	}
	if (num == 8) {
		if (left == 7 || left == 5 || left == 0) {
			ld = 1;
		}
		else if (left == 4 || left == 2 || left==10) {
			ld = 2;
		}
		else if (left == 1) {
			ld = 3;
		}
		


		if (right == 0 || right == 5 || right == 9) {
			rd = 1;
		}
		else if (right == 6 || right == 2 || right==11) {
			rd = 2;
		}
		else if (right == 3 ) {
			rd = 3;
		}
		
	}
	if (num == 0) {
		if (left == 8 || left==10) {
			ld = 1;
		}
		else if (left == 7 || left == 5) {
			ld = 2;
		}
		else if (left == 4|| left == 2) {
			ld = 3;
		}
		else if(left==1){
			ld = 4;
		}

		if (right ==8 || right==11) {
			rd = 1;
		}
		else if (right == 5 || right == 9) {
			rd = 2;
		}
		else if (right == 6|| right == 2) {
			rd = 3;
		}
		else if (right == 3) {
			rd = 4;
		}

	}











	if (ld < rd) {
		result = "L";
	}
	else if (ld > rd) {
		result = "R";
	}
	else {
		result = "S";
	}
		
	
	return result;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int numSize = numbers.size();

	stack<int>leftStatus;
	stack<int>rightStatus;
	leftStatus.push(10);
	rightStatus.push(11);

	string imsi;
	for (int i = 0; i < numSize; i++) {
		
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7 ) {
			leftStatus.push(numbers[i]);
			answer.push_back('L');
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			rightStatus.push(numbers[i]);
			answer.push_back('R');
		}
		else {
			int a = leftStatus.top();
			int b = rightStatus.top();
			imsi = Compare(numbers[i], a, b);
			if (imsi == "L") {
				leftStatus.push(numbers[i]);
				answer.push_back('L');
			}
			else if(imsi == "R") {
				rightStatus.push(numbers[i]);
				answer.push_back('R');
			}
			else {
				if (hand == "right") {
					rightStatus.push(numbers[i]);
					answer.push_back('R');
				}
				else {
					leftStatus.push(numbers[i]);
					answer.push_back('L');
				}
			}
		}
	}


	//cout << answer << endl;
	
	return answer;
}



int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	solution(numbers, hand);
	

	



	return 0;
}
