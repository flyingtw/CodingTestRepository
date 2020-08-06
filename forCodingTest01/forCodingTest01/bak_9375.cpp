#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
void init();


int tc;
map<string, int>m;
vector<pair<string, int>>v;


int main() {
	init();
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int a; cin >> a;
		int ret = 1;
		v.clear();
		for (int j = 0; j < a; j++) {
			
			bool flag = false;
			
			string s1, s2;
			int num = 1;
			cin >> s1 >> s2;
			int n = (int)v.size();
			for (int a = 0; a < n; a++) {
				if (v[a].first == s2) {
					flag = true;
					break;
				}
			}
			if (flag == false) {// 없으면 vector에 추가
				v.push_back({ s2,1 });
			}
			else {// 있으면 
				int imsi = 0;
				for (int b = 0; b < v.size(); b++) {
					if (v[b].first == s2) {
						imsi = b;
					}
				}
				v[imsi].second++;
			}
			
		}
		for (int c = 0; c<v.size(); c++) {
			int aa = v[c].second + 1;
			ret = ret * aa;
		}
		cout << ret - 1 << endl;
	}
	


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}