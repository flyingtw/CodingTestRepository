#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;


vector<int> priorities1 = { 2, 1, 3, 2 };
int location1 = 2;

vector<int> priorities2 = { 1, 1, 9, 1, 1, 1 };
int location2 = 0;

vector<int> priorities3 = { 1,1,9 };
int location3 = 0;


int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int,int>>test;
	vector<pair<int, int>> result;
	for (int i = 0; i < priorities.size(); i++) {
		test.push_back(make_pair(i+1,priorities[i]));
		
	}
	while (test.size() != 0) {
		if (test.size() == 1) {
			result.push_back(make_pair(test.front().first, test.front().second));
			test.erase(test.begin());
			break;
		}
		else {
			int max_n = test.front().second;
			for (int i = 1; i < test.size(); i++) {
				if (max_n < test[i].second) {
					test.push_back(make_pair(test.front().first, test.front().second));
					test.erase(test.begin());
					break;
				}
				if (i == test.size() - 1 && max_n >= test[i].second) {
					result.push_back(make_pair(test.front().first, test.front().second));
					test.erase(test.begin());
				}
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		if (result[i].first == location + 1) {
			answer = i+1;
		}
	}
	return answer;
}


int main() {
	cout<<solution(priorities1, location1)<<endl;

	return 0;
}