#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

int N;


void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}




int main() {
	init();
	
	
	cin >> N;
	int cnt = 0;

	for (int i = 666; ; i++) {
		string target = to_string(i);
		if (target.find("666") != -1) {
			cnt++;
		}
		if (cnt == N) {
			cout << i;
			break;
		}

	}
	


	return 0;
}