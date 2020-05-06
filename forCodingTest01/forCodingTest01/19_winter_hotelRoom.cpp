#include <iostream>
#include <string>
#include <vector>

using namespace std;

//1.�� ���� �� �� ��û�� ������� ���� �����մϴ�.
//2.���� �����ϱ� ���ϴ� �� ��ȣ�� �����մϴ�.
//3.���� ���ϴ� ���� ��� �ִٸ� ��� �����մϴ�.
//4.���� ���ϴ� ���� �̹� �����Ǿ� ������ ���ϴ� �溸�� ��ȣ�� ũ�鼭 
//  ����ִ� �� �� ���� ��ȣ�� ���� ���� �����մϴ�.\


long long k = 10;
vector<long long> room_number = {1,3,4,1,3,1};


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    // 1~k������ imsi �� 0���� �ʱ�ȭ ���� (0���� ����)
    // 0�� �����̶�� ��
    vector<long long>imsi(k+1);

    int client = room_number.size();//6���� �մ�
    for (int i = 0; i < client; i++) {
        //room_number[i] ��, i��° �մ��� ���ϴ� ���� �������� üũ
        if (imsi[room_number[i]] == 0) {
            answer.push_back(room_number[i]);
            imsi[room_number[i]] = room_number[i] + 1;
        }
        else {//�̹� �������� �ִ¹��̸�
            answer.push_back(imsi[room_number[i]]);
            imsi[imsi[room_number[i]]] = imsi[room_number[i]] + 1;
        }
        // 0���� 0���������� �ִ밪���� �ʱ�ȭ�ϱ�
        //->�Լ������
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