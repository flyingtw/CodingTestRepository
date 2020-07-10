#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int N;
vector<pair<int, int>> people;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


int check(int a,int b) {
	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (a < people[i].first && b < people[i].second) {
			rank += 1;
		}
	}
	return rank;
}



int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int m, h;
		cin >> m >> h;
		people.push_back(make_pair(m,h));
	}
	for (int i = 0; i < N; i++) {
		cout << check(people[i].first, people[i].second) << " ";
	}

	



	return 0;
}