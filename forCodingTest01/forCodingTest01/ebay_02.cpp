#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int num = 1;
vector<int> cards = { 1 };
//int num = 18;
//vector<int> cards = { 1,2,5 };


bool visited[100000];
int level = 0;
int ret = 2100000000;

int solution(int num, vector<int> cards) {
	int answer = 0;
	
	queue<int>q;
	for (int i = 0; i < (int)cards.size(); i++) {
		if (cards[i] == num)ret = 1;
		q.push({ cards[i] });
		visited[cards[i]] = true;
	}
	level = 1;
	while (!q.empty()) {
		
		int qs = q.size();
		while (qs--) {
			int cur_x = q.front();
			q.pop();
			for (int j = 0; j < (int)cards.size(); j++) {

				int nx = cur_x + cards[j];
				//cout << "nx :" << nx << endl;
				//cout << "level :" << level << endl;
				if (nx == num) {

					ret = min(level, ret);

				}

				if (nx < 0 || nx>100000) continue;
				if (nx > num)continue;
				if (visited[nx] == true)continue;
				if (visited[nx] == false) {
					q.push({ nx });
					visited[nx] = true;
				}
			}
		}
		level++;
		
	}
	if (ret == 2100000000) {
		cout << ret<<endl;
		return -1;
	}
	else if (ret == 1) {
		return 1;
	}
	else {
		cout << ret + 1;
		return ret + 1;
	}
	
	
}

int main() {
	init();
	solution(num, cards);

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}