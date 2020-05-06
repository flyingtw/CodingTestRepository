#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//¡�˴ٸ��� �Ϸķ� ���� �ְ� �� ¡�˴ٸ��� ��������� ��� ���ڰ� ���� ������ 
//������� ���ڴ� �� �� ���� ������ 1�� �پ��ϴ�.

//������� ���ڰ� 0�� �Ǹ� �� �̻� ���� �� ������ 
//�̶��� �� ���� ������� �ѹ��� ���� ĭ�� �ǳ� �� �� �ֽ��ϴ�.

//��, �������� ���� �� �ִ� ������� ���� ���� ��� 
//������ ���� ����� ������θ� �ǳʶ� �� �ֽ��ϴ�.

vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
int k = 3;
/*
int solution(vector<int> stones, int k) {
    int answer = 0;

    

    int stone_cnt = stones.size();
    
    vector<long long>imsi(stone_cnt);
    for (int i = 0; i < stone_cnt; i++) {
        imsi[i] = i;
    }
    for (int i = 0; i < imsi.size(); i++) {
        cout << imsi[i] << " ";
    }
    
    cout << endl;
    while (1) {
        cout << "-----����----" << endl;
        for (int i = 0; i < imsi.size(); i++) {
            if (stones[imsi[i]] > 0) {
                imsi[i] = i;
                stones[imsi[i]]--;
            }
            
            else {
                imsi.erase(imsi.begin() + i);
            }
        }
        for (int i = 0; i < stones.size(); i++) {
            cout << stones[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < imsi.size(); i++) {
            cout << imsi[i] << " ";
        }
        cout << endl;
        cout << "-----��---" << endl;
    }

    /*
    for (int i = 0; i < stones.size(); i++) {
        cout << stones[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < imsi.size(); i++) {
        cout << imsi[i] << " ";
    }

    
    
    
    return answer;
}
*/


//2��Ž������ Ǫ�°��̿���
bool binary_search(int& mid, int& k, vector<int>& v) {
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] - mid <= 0) {
            count++;
            if (count == k) return false;
        }
        else {
            count = 0;
        }
    }
    return true;

}

int solution(vector<int> stones, int k) {
    

    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (binary_search(mid, k, stones)) {
            left = mid + 1;
        }
        else {
            right = mid -1;
        }

    }
    return left;

}


int main() {

    cout<<solution(stones, k);

    return 0;
}