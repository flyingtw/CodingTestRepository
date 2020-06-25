#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define endl "\n"


using namespace std;


string s1 = "-1 2 3 4";
string s2 = "-1 -2 -3 -4";
string s3 = "-1 -1";
string solution(string s) {
    string answer = "";


    vector<int>imsi;

    string token;
    stringstream ss(s);
    while (getline(ss, token, ' ')) {
        imsi.push_back(stoi(token));
    }
    int min_val = imsi[0];
    int max_val= imsi[0];
 
    for (int i = 0; i < imsi.size(); i++) {
        min_val = min(min_val, imsi[i]);
        max_val = max(max_val, imsi[i]);
    }
    answer = to_string(min_val) + " " + to_string(max_val);



    return answer;
}



int main() {

    solution(s2);

	return 0;
}