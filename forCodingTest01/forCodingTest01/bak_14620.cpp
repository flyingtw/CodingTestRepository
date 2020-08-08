#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void init();
void print();

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N;
int money_arr[11][11];
bool flower_arr[11][11];
bool visited[11][11];
int ret = 1000000000;

int sum_money() {
	int total_money = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (flower_arr[i][j] == 1) {
				total_money += money_arr[i][j];
			}
		}
	}
	return total_money;
}


void seed(int seedN) {
	if (seedN == 3) {
		//print();
		//cout << "----------------" << endl;
		int imsi = sum_money();
		if (ret == -1 && imsi >=0) {
			ret = imsi;
		}
		else {
			ret = min(imsi, ret);
		}
		return;
	}
	
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {//����� Ž��(�׵θ� ����)
			bool flag = false;

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (flower_arr[ny][nx] == true) {
					flag = true;
					break;
				}
			}
			if (flag == true) {// ��ġ�� �κ��� �߻��ϸ� ���������� �̵�
				continue;
			}
			//��ġ�� �κ��� ������ �� �ڸ��� üũ
			flower_arr[i][j] = true;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				flower_arr[ny][nx] = true;
			}
			//�� ó�� �� �ϸ� �ɾ� �߰�����
			seed(seedN + 1);

			//�߰��Ѵ����� �ɾ� ����
			flower_arr[i][j] = false;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				flower_arr[ny][nx] = false;
			}

		}
	}

}


int main() {
	init();
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> money_arr[i][j];
		}
	}
	seed(0);



	//print();
	cout << ret;




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < N; j++) {
			cout << flower_arr[i][j] << " ";
		}
	}
}