#include<bits/stdc++.h>


using namespace std;

int T;
int N;

//n�� ���μ����� �Ͽ����� 2�Ǵ� 5�� ������ �������� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int two = 0;
		int five = 0;
		cin >> N;
		for (int a = 2; a <= N; a *= 2) {
			two += (N / a);
		}
		for (int a = 5; a <= N; a *= 5) {
			five += (N / a);
		}
		cout << min(two, five)<<"\n";
	}
	



	return 0;
}