#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//징검다리는 일렬로 놓여 있고 각 징검다리의 디딤돌에는 모두 숫자가 적혀 있으며 
//디딤돌의 숫자는 한 번 밟을 때마다 1씩 줄어듭니다.

//디딤돌의 숫자가 0이 되면 더 이상 밟을 수 없으며 
//이때는 그 다음 디딤돌로 한번에 여러 칸을 건너 뛸 수 있습니다.

//단, 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 
//무조건 가장 가까운 디딤돌로만 건너뛸 수 있습니다.

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
        cout << "-----시작----" << endl;
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
        cout << "-----끝---" << endl;
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


//2분탐색으로 푸는것이여따
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