#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;


//baseball의 각 행은 [세 자리의 수, 스트라이크의 수, 볼의 수] 를 담고 있습니다.
vector<vector<int>> baseball= {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for (int i = 123; i <= 987; i++) {
        int x = i / 100;
        int y = (i - x * 100) / 10;
        int z = i % 10;
        if (x==y || y==z || z==x) continue;
        if (x==0 || y==0|| z==0) continue;
        
        for (int j = 0; j < baseball.size(); j++) {
            int strike = 0;
            int ball = 0;

            int num = baseball[j][0];
            int num_x = num / 100;
            int num_y = (num - num_x * 100) / 10;
            int num_z = num % 10;

            if (num_x == 0 || num_y == 0 || num_z == 0) break;
            if (num_x == x) strike++;
            if (num_y == y) strike++;
            if (num_z == z) strike++;
            if (baseball[j][1] != strike) break;

            if (num_x == y || num_x == z) ball++;
            if (num_y == z || num_y == x) ball++;
            if (num_z == x || num_z == y) ball++;
            if (baseball[j][2] != ball) break;
                

        }
        




    }


   


    return answer;
}

int main() {




    cout << solution(baseball) << endl;



    return 0;
}