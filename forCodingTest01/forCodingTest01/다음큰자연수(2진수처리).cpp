#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int n = 78;


int solution(int n) {
    
    
    int num = bitset<20>(n).count();// 10���� -> 2���� ��ȯ ��, 1�� ���� ī��Ʈ
    int i = n + 1;// n���ڿ��� 1�� ���ϱ� 78, 79, 80, 81...
    while (bitset<20>(i).count() != num) {
        i++;// n���ڿ��� 1�� ���ϱ� 78, 79, 80, 81...
    }
    

    return i;
}

int main() {
    solution(n);

    return 0;
}