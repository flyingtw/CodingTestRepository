#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();


vector<string> info = {
    "java backend junior pizza 150",
    "python frontend senior chicken 210",
    "python frontend senior chicken 150",
    "cpp backend senior pizza 260",
    "java backend junior chicken 80",
    "python backend senior chicken 50"
};

vector<string> query = {
    "java and backend and junior and pizza 100",
    "python and frontend and senior and chicken 200",
    "cpp and - and senior and pizza 250",
    "- and backend and senior and - 150",
    "- and - and - and chicken 100",
    "- and - and - and - 150"
};




string arr[4][50001];



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < (int)info.size(); i++) {
        stringstream ss(info[i]);
        string k;
        int num = 0;
        while (ss >> k) {
            //cout << num << " ";
            //cout << k << endl;
            arr[num][i] = k;
            num++;
        }
        ss.clear();
    }

    for (int i = 0; i < 4; i++) {
        cout << endl;
        for (int j = 0; j < info.size(); j++) {
            cout << arr[i][j] << " ";
        }
    }

    for (int i = 0; i < (int)query.size(); i++) {
        stringstream ss(query[i]);
        string k;
        string tmp[4];
        int num = 0;
        while (ss >> k) {
            //cout << num << " ";
            //cout << k << endl;
            tmp[0] = k;
            num++;
        }
        cout << tmp[0] << " " << tmp[3] << endl;
        ss.clear();
    }






    return answer;
}

int main() {
	init();
    solution(info, query);
	

	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}