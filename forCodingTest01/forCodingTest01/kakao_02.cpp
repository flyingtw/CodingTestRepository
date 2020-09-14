#include <bits/stdc++.h>

#define endl "\n"
using namespace std;
void init();

vector<string> orders = 
{ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
vector<int> course = { 2,3,5 };

bool check[30];
vector<pair<char,bool>>al;

vector<char>v3;
vector<string>answers;

vector<pair<int, string>>v2;

vector<string>real_answer;




void fc1(string s1) {

	int ret = 0;

	
	for (int i = 0; i < (int)orders.size(); i++) {
		int num = 0;
		for (int k = 0; k < s1.length(); k++) {
			char imsi = s1[k];
			for (int j = 0; j < orders[i].length(); j++) {
				// orders[i]=ABCFG
				// orders[i][j]=A
				if (imsi == orders[i][j]) {
					num++;
					break;
				}
				else continue;
			}
		}
		if (num == s1.length()) {
			//cout << "¿©±â " << s1 << 
			ret++;
		}
	}
	
	
	//cout << s1 << " " << ret << endl;
	v2.push_back({ ret,s1 });
	
	
}

void combi(int here,int m) {
	if ((int)v3.size() == m) {

		string s="";
		for (auto it : v3) {
			s.push_back(al[it].first);
			//cout << al[it].first<<" ";	
		}
		fc1(s);
		
	}
	for (int i = here + 1; i < al.size(); i++) {
		v3.push_back(i);
		combi(i,m);
		v3.pop_back();
	}
}


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	int num = 0;

	for (int i = 0; i < (int)orders.size(); i++) {
		for (int j = 0; j < orders[i].length(); j++) {
			if (check[orders[i][j] - 65] == false) {
				check[orders[i][j] - 65] = true;
				al.push_back({ orders[i][j],false });
				num++;
			}
		}
	}
	sort(al.begin(), al.end());
	/*for (int i = 0; i < al.size(); i++) {
		cout << al[i].first << " ";
	}
	*/
	for (int i = 0; i < (int)course.size(); i++) {
		int m = course[i];
		v2.clear();
		
		combi(-1, m);
		sort(v2.begin(), v2.end());
		int aa = v2[v2.size() - 1].first;
		if (aa >= 2) {
			for (int i = v2.size() - 1; i > 0; i--) {
				if (v2[i].first == aa) {
					real_answer.push_back(v2[i].second);
				}
				else if (v2[i].first == v2[i - 1].first && v2[i - 1].first == aa) {
					real_answer.push_back(v2[v2.size() - 1].second);
				}

			}
		}

		
		/*for (int a = 0; a < answer2.size(); a++) {
			cout << answer2[i].first << endl;
		}

		for (int i = 0; i < 26; i++) {
			cout << check[i] << " ";
		}

		for (int i = 0; i < answers.size(); i++) {
			cout << answers[i] << endl;
		}*/


		
	}
	sort(real_answer.begin(), real_answer.end());
	answer = real_answer;
	return answer;
}

int main() {
	init();

	solution(orders, course);

	sort(real_answer.begin(), real_answer.end());
	for (int i = 0; i < (int)real_answer.size(); i++) {
		cout << real_answer[i] << endl;
	}


	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}