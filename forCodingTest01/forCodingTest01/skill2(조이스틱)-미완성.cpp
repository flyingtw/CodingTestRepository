#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

// name ���̴� 1~20
// ȭ��ǥ �����¿� ������� �󸶳� �ּҷ� �������� �ϴ��� return
// �ʱ� �̸����� AAA~~�� ����
string name1 = "JEROEN";
string name2 = "JAN";

// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
//26  25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1

int solution(string name) {
    int answer = 0;
    cout << name << endl;


    return answer;
}

int main() {
    solution(name1);

    vector<int>test;
    for (int i = 0; i < 4; i++) {
        test.push_back(i+1);
    }
    int n = 0;
    do {
        n++;
        if (n == 3) {
            for (int i = 0; i < 4; i++) {
                cout << test[i] << " ";
            }
            cout << '\n';
        }
        else {

            cout << '\n';

        }
    } while (next_permutation(test.begin(), test.end()));



    vector< int > CharItems; 
    CharItems.push_back(11); 
    CharItems.push_back(100); 
    CharItems.push_back(77); 
    vector< int >::iterator FindIter; 
    // CharItems�� ó���� ������ 12�� ã�´�. 
    FindIter = find( CharItems.begin(), CharItems.end(), 12 ); 
    if( FindIter != CharItems.end() ) { 
        cout << "CharItem 12�� ã�ҽ��ϴ�." << endl; 

    } else { cout << "CharItem 12�� �����ϴ�" << endl; }



	return 0;
}