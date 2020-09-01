#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, x, y;
bool flag = false;
int num = 1;

void fc1(int x1, int y1) {
	x = x1;
	y = y1;
	if (x % 2 == 1) {
		//cout << "È¦¼ö" << " " << x << endl;
		x = x / 2+1;
	}
	else {
		//cout << "Â¦¼ö" <<" "<<x<< endl;
		x = x / 2 ;
	}
	if (y % 2 == 1) {
		//cout << "È¦¼ö" << " " << y << endl;
		y = y / 2 + 1;
	}
	else {
		//cout << "Â¦¼ö" << " " << y << endl;
		y = y / 2;
	}
	num++;
	
	if (x == y) {
		
		flag = true;
	}
	//cout << "-----------" << endl;
}

int main() {
	init();

	cin >> N >> x >> y;
	
	while (!flag) {
		fc1(x,y);
		
	}
	cout << num - 1 << endl;
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}