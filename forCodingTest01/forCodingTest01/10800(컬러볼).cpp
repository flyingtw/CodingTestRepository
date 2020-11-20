#include <bits/stdc++.h>
#define endl "\n"
using namespace std;



int N;


typedef pair<int,pair<int, int>>P;
typedef pair<int, int>P2;
vector<P>v;







bool cmp(P a, P b) {
	return a.second.second < b.second.second;
}
bool cmp2(P2 a, P2 b) {
	return a.first < b.first;
}

void init();
int main() {
	init();

	cin >> N;
	// 공 색깔, 공 크기
	for (int i = 0; i < N; i++) {
		int color, size; cin >> color >> size;
		v.push_back({ i,{ color,size } });

	}
	// 당연하게도 시간초과남 O(N*N) 임
	/*vector<int>ans;
	for (int i = 0; i < N; i++) {
		int imsi = 0;
		for (int j = 0; j < N; j++) {
			int cmp_color = v[j].first;
			int cmp_size = v[j].second;

			if (v[i].first == cmp_color)continue;
			if (v[i].second > cmp_size) {
				imsi += cmp_size;
			}
		}
		ans.push_back(imsi);
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << endl;
	}*/

	// -> 정렬해서 기준까지 ?  v.second 오름차순으로 정렬

	
	sort(v.begin(), v.end(), cmp);
	vector<pair<int, int>>ans;

	for (int i = 0; i < N; i++) {
		int cmp_n = v[i].first;
		int cmp_color = v[i].second.first;
		int cmp_size = v[i].second.second;
		int weight = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)continue;

			int cng_color = v[j].second.first;
			int cng_size = v[j].second.second;

			if (cmp_color != cng_color) {
				if (cmp_size > cng_size) {
					weight += cng_size;
				}
				else {
					break;
				}
			}
		}
		/*cout << "---" << endl;
		cout << cmp_n << " " << weight << endl;
		cout << "---" << endl;*/
		ans.push_back({ cmp_n,weight });

	}

	// 정렬해서 출력하기
	/*for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second.first<<" " <<v[i].second.second <<endl;
	}*/

	sort(ans.begin(), ans.end(), cmp2);

	for (int i = 0; i < N; i++) {
		cout << ans[i].second << endl;
	}

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}