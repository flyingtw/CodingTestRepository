#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, M;
int result = 1000;

string white[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}
};
string black[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}
};

string board[50];

void init() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
}

void check_B(int x, int y) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (black[i][j] != board[y + i][x + j]) {
                num++;
            }
        }
    }
    result = min(result, num);
}

void check_W(int x, int y) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (white[i][j] != board[y + i][x + j]) {
                num++;
            }
        }
    }
    result = min(result, num);
}

int main() {
	init();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int x = 0; x < M-7; x++) {
        for (int y = 0; y < N-7; y++) {
            check_W(x, y);
            check_B(x, y);
        }
    }
    cout << result;


	return 0;
}