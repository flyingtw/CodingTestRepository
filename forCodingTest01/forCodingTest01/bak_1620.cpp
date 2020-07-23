#include<bits/stdc++.h>


#define endl "\n"

using namespace std;

int N, M;
//vector<pair<int,string>>v1;
map<string, int>m1;
string arr[100001];

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}


int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s1; cin >> s1;
		//v1.push_back({ i + 1,s1 });
		m1.insert(make_pair(s1,i+1));
		arr[i] = s1;
	}
	
	map<string,int>::iterator itr;
	for (int i = 0; i < M; i++) {
		string s2; cin >> s2;
		if (atoi(s2.c_str()) == 0) {//문자열일 경우 숫자 반환
			cout << m1.find(s2)->second << endl;
		}
		else {//숫자일 경우 문자열 반환
			cout << arr[stoi(s2) - 1] << endl;
			
		}
	}
	// map(m1)을 통해 key 값(포켓몬이름) 으로 value(도감번호)를 출력
	


	
	
	


	return 0;
}