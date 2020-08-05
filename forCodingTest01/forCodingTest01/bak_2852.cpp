#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int N;
int score[2] = { 0,0 };
int t1_h=0, t1_m=0;
int t2_h = 0, t2_m = 0;
int imsi_h = 0;
int imsi_m = 0;

int flag_hh=0;
int flag_mm=0;
int winning = -1;
vector<pair<int, int>>v = { {0,0},{0,0} };


void init();

void timecal(int team,int old_h, int old_m,int new_h,int new_m) {
	int n_h;
	int n_m;
	
	n_h = new_h-old_h;
	if (new_m - old_m < 0) {
		n_m = 60 + new_m - old_m;
		n_h -= 1;
	}
	else {
		n_m = new_m - old_m;
	}
	
	v[team].first += n_h;
	v[team].second += n_m;

}

int main() {
	init();
	cin >> N;
	for (int i = 0; i <= N; i++) {
		int nhh, nmm;
		if (i == N) {
			if (score[0] > score[1])winning = 1;
			if (score[0] < score[1])winning = 2;
			if (score[0] == score[1])winning = -1;
			nhh = 48;
			nmm = 0;
		}
		else {
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
			if (score[0] > score[1])winning = 1;
			if (score[0] < score[1])winning = 2;
			if (score[0] == score[1])winning = -1;

			if (t == 1)score[0]++;
			else score[1]++;
		}
	/*	cout << "이전 min : " << flag_hh << endl;
		cout << "이전 sec : " << flag_mm << endl;
		cout << "지금 min : " << nhh << endl;
		cout << "지금 sec : " << nmm << endl;
		cout << "팀 1 점수 : " << score[0] << endl;
		cout << "팀 2 점수 : " << score[1] << endl;
		cout << "방금 넣기전까지 이기던 팀 : " << winning << endl;
		cout << "---------------------------------" << endl;*/
		if (winning == 1) {
			timecal(0, flag_hh, flag_mm, nhh, nmm);
		}
		else if (winning == 2) {
			timecal(1, flag_hh, flag_mm, nhh, nmm);
		}
		flag_hh = nhh;
		flag_mm = nmm;
		
	}
	for (int i = 0; i < (int)v.size(); i++) {
		string mm = to_string(v[i].first);
		string ss = to_string(v[i].second);
		if (mm.length() == 1) {
			mm = "0" + mm;
		}
		if (ss.length() == 1) {
			ss = "0" + ss;
		}
		cout << mm << ":" << ss << endl;
		
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}