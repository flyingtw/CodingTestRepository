#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

// name 길이는 1~20
// 화살표 상하좌우 기반으로 얼마나 최소로 움직여야 하는지 return
// 초기 이름값은 AAA~~로 시작
string name1 = "JEROEN";
string name2 = "JAN";
string name3 = "CAZAAZAAZAZ";

// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
//26  25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1



//int move(string name, int idx) {
//    int answer;
//    int l, r;
//    int c_l, c_r, i_l, i_r;
//
//    l = r = c_l = c_r = 0;
//    if (name[idx] != 'A') name[idx] = 'A';
//    if (name == string(name.size(), 'A')) return 0;
//
//    for (int i = idx + 1;; i++) {
//        r++;
//        if (i == name.size()) i = 0;
//        if (name[i] != 'A') break;
//    }
//    i_r = r + idx > name.size() ? r + idx - name.size() : r + idx;
//    for (int i = idx - 1;; i--) {
//        l++;
//        if (i < 0) i = name.size() - 1;
//        if (name[i] != 'A') break;
//    }
//    i_l = idx - l < 0 ? idx - l + name.size() : idx - l;
//
//    c_r += r + move(name, i_r);
//    c_l += l + move(name, i_l);
//
//    c_r > c_l ? answer = c_l : answer = c_r;
//
//    return answer;
//}


int solution(string name) {
    int answer = 0;
    int answer2 = 0;
    int size = name.size();
    string a = "KIMTAEWAN";

    for (char i : a) {
        i - 65 > 12 ? answer += 1 : answer2 += 1;
    }
    cout << answer << endl;
    cout << answer2 << endl;

   // answer += move(name, 0);

    return answer;


}

int main() {
    //solution(name3);

    //vector<int>test;
    //for (int i = 0; i < 4; i++) {
    //    test.push_back(i+1);
    //}
    //int n = 0;
    //do {
    //    n++;
    //    if (n == 3) {
    //        for (int i = 0; i < 4; i++) {
    //            cout << test[i] << " ";
    //        }
    //        cout << '\n';
    //    }
    //    else {

    //        cout << '\n';

    //    }
    //} while (next_permutation(test.begin(), test.end()));



    //vector< int > CharItems; 
    //CharItems.push_back(11); 
    //CharItems.push_back(100); 
    //CharItems.push_back(77); 
    //vector< int >::iterator FindIter; 
    //// CharItems의 처음과 끝에서 12를 찾는다. 
    //FindIter = find( CharItems.begin(), CharItems.end(), 12 ); 
    //if( FindIter != CharItems.end() ) { 
    //    cout << "CharItem 12를 찾았습니다." << endl; 

    //} else { cout << "CharItem 12는 없습니다" << endl; }

    int a = 5;
    string test;
    a>1 ? test="a는 1보다 큼": test="a는 1보다 작음";
    cout << test << endl;

    int a = 5;
    string test;
    if (a > 1) {
        test = "a는 1보다 큼";
    }
    else {
        test = "a는 1보다 작음";
    }



	return 0;
}