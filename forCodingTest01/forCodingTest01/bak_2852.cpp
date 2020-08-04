#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int score[2] = { 0,0 };
int t1_h=0, t1_m=0;
int t2_h = 0, t2_m = 0;
int imsi_h = 0;
int imsi_m = 0;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}

void timecal(int h, int m,int t,int ms) {
	int n_h;
	int n_m;
	int old_h = imsi_h;
	int old_m = imsi_m;
	n_h = h-old_h;
	if (m - old_m < 0) {
		n_m = 60 + m - old_m;
		n_h -= 1;
	}
	else {
		n_m = m - old_m;
	}
	
	cout << "계산된 시간 " << n_h << " " << n_m << endl;
	
	if (t == t1_h) {
		t1_h += n_h;
		t1_m += n_m;
	}
	else {
		t2_h += n_h;
		t2_m += n_m;
	}
	
}

int main() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
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
		int nhh = stoi(hh);
		int nmm = stoi(mm);
		
		//(nhh, nmm) = timecal(nhh, nmm);



		if (t == 1)score[0]++;
		else score[1]++;
		if (score[0] > score[1]) {// 1팀이 이기고 있으면
			
			timecal(nhh, nmm,t1_h,t1_m);
			
			
			
			cout << "1팀 이기는중" << endl;
			cout << "1팀 누적 시간 :"<<t1_h << " " << t1_m << endl;
			cout << "2팀 누적 시간 :"<<t2_h << " " << t2_m << endl;
			
		}
		if (score[0] < score[1]) {// 2팀이 이기고 있으면
			
			timecal(nhh, nmm, t2_h, t2_m);

			cout << "2팀 이기는중" << endl;
			cout << "1팀 누적 시간 :" << t1_h << " " << t1_m << endl;
			cout << "2팀 누적 시간 :" << t2_h << " " << t2_m << endl;

		}
		imsi_h = nhh;
		imsi_m = nmm;

		cout << "--------------------" << endl;

	}
	if (score[0] < score[1]) {

	}



	return 0;
}
