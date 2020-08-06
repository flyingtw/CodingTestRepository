#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int t1[3000];
int t2[3000];
int ret1=0;
int ret2=0;



void init();


int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int nhh, nmm, ss;
		int t;
		string s;
		cin >> t >> s;
		string hh = "";
		string mm = "";
		for (int i = 0; i < 2; i++) {
			hh += s[i];
		}
		for (int i = 3; i <= 4; i++) {
			mm += s[i];
		}
		nhh = stoi(hh);
		nmm = stoi(mm);
		ss = (nhh * 60) + nmm;

		if (t == 1) {
			for (int j = ss + 1; j <= 2880; j++) {
				t1[j] += 1;
			}
		}
		else {
			for (int j = ss + 1; j <= 2880; j++) {
				t2[j] += 1;
			}
		}
		


	}
	for (int a = 0; a <= 2880; a++) {
		if (t1[a] != t2[a]) {
			if (t1[a] > t2[a]) {
				ret1++;
			}
			else {
				ret2++;
			}
		}
		else {
			continue;
		}
	}
	printf("%02d:%02d\n", ret1 / 60, ret1 - (ret1 / 60) * 60);
	printf("%02d:%02d\n", ret2 / 60, ret2 - (ret2 / 60) * 60);
	//cout << ret1/60<<":" << ret1-(ret1/60)*60<<endl;
	//cout << ret2 << endl;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}