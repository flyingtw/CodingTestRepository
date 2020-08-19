#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

char arr[10][10];
bool alpha[13];
vector<pair<int, int>>xv;
vector<pair<int, int>>numv;



void permu(int n) {

}

int main() {
	init();
	// A~L 까지 가능
	// X면 빈칸, 좌표 저장
	// A~L 이면 숫자화(-'A') 하고 좌표 저장
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 9; j++) {
			if (s[j] >= 'A' && s[j] <= 'L') {
				alpha[s[j] - 'A' + 1] = true;
				numv.push_back({ i,j });
			}
			if (s[j] == 'x') {
				xv.push_back({ i,j });
			}
			arr[i][j]=s[j];
		}
	}

	//            (0,4)
	// (1,1), (1,3), (1,5), (1,7)
	//     (2,2),        (2,6)
	// (3,1), (3,3), (3,5), (3,7)
	//            (4,4)
	
	permu(0);


	

	for (int i = 1; i < 13; i++) {
		cout << alpha[i] << " ";
	}
	cout << endl;
	



	/*char imsi = 'A';
	cout << imsi - 'A'+1;*/




	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}







#include <iostream>
using namespace std;

int position[12][2] = { {0,1},{3,4},{0,3},{1,3},{3,5},{0,4},{1,5},{0,2},{2,4},{2,5},{1,2},{4,5} }, count_num[6], count_bingo[6];
char c[12];
bool check[27];

void btk(int idx) {
    for (int i = 0; i < 6; i++) {
        if (count_bingo[i] == 4 && count_num[i] != 26)
            return;
    }

    while (c[idx] != 'x' && idx <= 11)
        idx++;

    if (idx == 12) {
        for (int i = 0; i < 6; i++) {
            if (count_bingo[i] != 4 || count_num[i] != 26)
                break;
            if (i == 5) {
                cout << "...." << c[0] << "....\n" << "." << c[1] << "." << c[2] << "." << c[3] << "." << c[4] << ".\n.." << c[5] << "..." << c[6] << "..\n." << c[7] << "." << c[8] << "." << c[9] << "." << c[10] << ".\n...." << c[11] << "....";
                exit(0);
            }
        }
    }

    for (int j = 1; j <= 26; j++) {
        if (!check[j]) {
            check[j] = 1;
            c[idx] = char(j + 64);
            count_num[position[idx][0]] += (int)c[idx] - 64;
            count_num[position[idx][1]] += (int)c[idx] - 64;
            count_bingo[position[idx][0]]++;
            count_bingo[position[idx][1]]++;
            btk(idx + 1);
            count_bingo[position[idx][0]]--;
            count_bingo[position[idx][1]]--;
            count_num[position[idx][0]] -= (int)c[idx] - 64;
            count_num[position[idx][1]] -= (int)c[idx] - 64;
            c[idx] = 'x';
            check[j] = 0;
        }
    }
}

int main() {
    int p = 0;
    for (int i = 0; i < 45; i++) {
        char tmp; cin >> tmp;
        if (tmp != '.') {
            c[p] = tmp;
            if (c[p] != 'x') {
                check[(int)c[p] - 64] = 1;
                count_bingo[position[p][0]]++;
                count_bingo[position[p][1]]++;
                count_num[position[p][0]] += (int)c[p] - 64;
                count_num[position[p][1]] += (int)c[p] - 64;
            }
            p++;
        }
    }

    btk(0);
}