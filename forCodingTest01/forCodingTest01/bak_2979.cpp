#include <iostream>


#define endl "\n"

using namespace std;

int A, B, C;
int arr[100];
int total = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


int main() {
	init();
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int in, out; cin >> in>> out;
		for (int i = in; i < out; i++) {
			arr[i]++;
		}

	}
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 1) {
			total += 1 * A;
		}
		if (arr[i] == 2) {
			total += 2 * B;
		}
		if (arr[i] == 3) {
			total += 3 * C;
		}
	}
	cout << total << endl;





	return 0;
}