#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int n;

vector<int> answer;


void bfs(int a) {
	queue<int>q;
	q.push(a);

	int level = 1;

	while (!q.empty()) {

		int q_size = q.size();
		
		while (q_size--) {
			int cur_a = q.front();
			q.pop();

			string s = to_string(cur_a);//73425
			int a_size = s.length();//5
			for (int i = 0; i < a_size - 1; i++) {
				string s1 = "";
				string s2 = "";
				for (int j = 0; j <= i; j++) {
					s1.push_back(s[j]);
				}
				for (int j = i + 1; j <= a_size - 1; j++) {
					s2.push_back(s[j]);
				}
				if (s1[0] == '0')continue;
				if (s2[0] == '0')continue;

				int na = stoi(s1) + stoi(s2);

				if (na >= 1 && na <= 9) {
					answer.push_back(level);
					answer.push_back(na);
					return;
				}
				else {
					q.push(na);
				}

			}
		}
		level++;
	}
	
	
	
}

vector<int> solution(int n) {
	
	if (n >= 1 && n <= 9) {
		answer = { 0,n };
	}
	else {
		bfs(n);
	}
	

	
	return answer;
}

int main() {
	init();

	solution(n);



	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}