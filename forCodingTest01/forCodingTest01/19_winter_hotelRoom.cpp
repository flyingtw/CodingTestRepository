#include <iostream>
#include <string>
#include <vector>

using namespace std;

//1.한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
//2.고객은 투숙하기 원하는 방 번호를 제출합니다.
//3.고객이 원하는 방이 비어 있다면 즉시 배정합니다.
//4.고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 
//  비어있는 방 중 가장 번호가 작은 방을 배정합니다.\


long long k = 10;
vector<long long> room_number = {1,3,4,1,3,1};


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    // 1~k번까지 imsi 방 0으로 초기화 배정 (0번방 제외)
    // 0은 공실이라는 뜻
    vector<long long>imsi(k+1);

    int client = room_number.size();//6명의 손님
    for (int i = 0; i < client; i++) {
        //room_number[i] 즉, i번째 손님이 원하는 방이 공실인지 체크
        if (imsi[room_number[i]] == 0) {
            answer.push_back(room_number[i]);
            imsi[room_number[i]] = room_number[i] + 1;
        }
        else {//이미 누군가가 있는방이면
            answer.push_back(imsi[room_number[i]]);
            imsi[imsi[room_number[i]]] = imsi[room_number[i]] + 1;
        }
        // 0부터 0만날때까지 최대값으로 초기화하기
        //->함수만들기
        int first = 0;
        int second = 0;
        for (int a = 0; a < imsi.size(); a++) {
            if (imsi[a] != 0 && imsi[a + 1] == 0) {
                second = a + 1;
                for (int b = a; b >= first + 1; b--) {
                    if (imsi[b] != 0) {
                        imsi[b] = imsi[a];
                    }
                }
                first = a + 1;
            }
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    
   

    return answer;
}


int main() {

    solution(k, room_number);
    
    /*
    vector<long long >test = {0, 2,3,0,4,5,6,0,9,0 };
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    int first = 0;
    int second = 0;
    



    cout << endl;
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }


    */


    return 0;
}