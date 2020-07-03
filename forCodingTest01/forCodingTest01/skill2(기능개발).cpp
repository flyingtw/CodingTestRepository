#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

vector<int> progresses = { 93,30,55 };
vector<int> speeds = { 1,30,5 };

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int num = progresses.size();
    queue<int>q;
    for (int i = 0; i < num; i++) {
        q.push(progresses[i]);
    }
    while (!q.empty()) {
        for (int i = 0; i < num; i++) {
            progresses[i] += speeds[i];


        }
    }
 




   
    return answer;
}

int main() {

    vector<int>real_answer = solution(progresses, speeds);

    for (int i = 0; i < real_answer.size(); i++) {
        cout << real_answer[i] << " ";
    }
    return 0;
}