#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int n = 78;


int solution(int n) {
    
    
    int num = bitset<20>(n).count();// 10진수 -> 2진수 변환 후, 1의 개수 카운트
    int i = n + 1;// n숫자에서 1씩 더하기 78, 79, 80, 81...
    while (bitset<20>(i).count() != num) {
        i++;// n숫자에서 1씩 더하기 78, 79, 80, 81...
    }
    

    return i;
}

int main() {
    solution(n);

    return 0;
}