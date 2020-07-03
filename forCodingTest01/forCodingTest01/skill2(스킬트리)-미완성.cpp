#include <iostream>
#include <vector>
#include <string>
#include <queue>


#define endl "\n"
using namespace std;

string skill = "CBD";
vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" ,"AQWER"};
// 스킬트리속에 스킬들이 순서대로 있는지 확인
// 답 : 3

// 다시해야함

int check_skill(queue<char> check_q, string check_skill) {
	int num = check_q.size();
	bool flag = false;
	int ok = 0;
	queue<char>skill_q;
	for (int i = 0; i < check_skill.length(); i++) {
		skill_q.push(check_skill[i]);
	}
	for (int i = 0; i < check_skill.length(); i++) {
		if (check_q.size()!=0 && check_q.front()==check_skill[i]) {
			check_q.pop();
			skill_q.pop();
			flag = true;
		}
		else {
			skill_q.pop();
		}
	}
	cout << check_q.size() << endl;
	if (check_q.size() > 1) {
		ok = 0;
		//cout << "비교문자 :" << check_skill << endl;
		//cout << "check_q.size :" << check_q.size() << endl;
	}
	else {
		ok = 1;
		cout << "비교문자 :"<<check_skill << endl;
		cout << "check_q.size :" << check_q.size() << endl;
	}

	cout << "-------" << endl;

	return ok;
}


int solution(string skill, vector<string> Tree) {
	int answer = 0;

	queue<char>sq;
	queue<char>treeq;
	for (int i = 0; i<skill.length(); i++) {
		sq.push(skill[i]);
	}

	for (int i = 0; i < Tree.size(); i++) {
		answer += check_skill(sq, Tree[i]);
	}
	



	return answer;
}


int main() {

	cout << solution(skill, skill_trees) << endl;


	return 0;
}