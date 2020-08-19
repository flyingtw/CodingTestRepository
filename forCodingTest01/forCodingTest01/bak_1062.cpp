#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

int N, K;
vector<string>v;
bool arr[30];
bool alpha[30];
string antic = "antic";
int learn;
int ret = 0;


void check() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			if (alpha[v[i][j]-'a'] == false) {
				break;
			}
			else {
				if (j == (int)v[i].size() - 1) {
					num++;
				}
				continue;
			}
			
		}
	}
	ret = max(ret, num);
}

void set_alphabet(int n) {
	if (n == learn) {
		check();
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == false) {
			alpha[i] = true;
			set_alphabet(n + 1);
			alpha[i] = false;
		}
	}
	
}


int main() {
	
	init();
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		v.push_back(s);
	}

	// antic 5개 제외하고 M개까지 ture 로 가능함 뽑은다음 모든 문자열 가능한지 체크
	// 1. M이 <5 이다. -> 아예 못배움 return 0;
	// 2. M이 5  이다. -> 그냥 체크
	// 3. M이 >5 이다. -> 나머지 true로 체크
	if (K < 5)return 0;
	learn = K - 5;//6이면 1개남음

	// antic 5개 true 처리
	for (int i = 0; i < 5; i++) {
		alpha[antic[i] - 'a'] = true;
	}
	set_alphabet(0);

	cout << ret;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}