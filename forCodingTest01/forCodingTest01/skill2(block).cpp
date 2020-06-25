#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define endl "\n"

using namespace std;

int m=6;
int n=6;
vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };

int m2 = 4;
int n2 = 5;
vector<string> board2={"CCBDE", "AAADE", "AAABF", "CCBBF"};

// 2x2 형태로 같은 블록 지우기
// 블록 매트릭스 활용 1. 스캔, 2. 지우기 반복




int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    int a = 0;
    int b = 0;
    while (1) {
        flag = false;
        for (int i = 0; i < board.size()-1 ; i++) {
            for (int j = 0; j < board[i].size() - 1; j++) {
                if (board[i][j]!='0' 
                    && tolower(board[i][j]) == tolower(board[i + 1][j]) 
                    && tolower(board[i][j]) == tolower(board[i][j + 1]) 
                    && tolower(board[i][j]) == tolower(board[i + 1][j + 1])) {
                        board[i + 1][j] = tolower(board[i][j]);
                        board[i][j+1]= tolower(board[i][j]);
                        board[i][j]= tolower(board[i][j]);
                        board[i+1][j+1]=tolower(board[i][j]);
                        flag = true;
                }
            }
        }
        if (flag == false)break;//스캔 후 변한게 없으니까 break;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }
        for (int i = board.size() - 1; i >= 0; i--) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '0') {
                    for (int z = i - 1; z >= 0; z--) {
                        if (board[z][j] != '0') {
                            board[i][j] = board[z][j];
                            board[z][j] = '0';
                            break;
                        }
                    }
                }
            }
        }
    }

    return answer;
}






int main() {



    cout << solution(m, n, board) << endl;


	return 0;
}