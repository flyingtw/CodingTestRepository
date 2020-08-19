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

	// antic 5�� �����ϰ� M������ ture �� ������ �������� ��� ���ڿ� �������� üũ
	// 1. M�� <5 �̴�. -> �ƿ� ����� return 0;
	// 2. M�� 5  �̴�. -> �׳� üũ
	// 3. M�� >5 �̴�. -> ������ true�� üũ
	if (K < 5)return 0;
	learn = K - 5;//6�̸� 1������

	// antic 5�� true ó��
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