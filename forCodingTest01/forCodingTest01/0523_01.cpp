#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;
vector<string>strs = { "abcaefg", "abcdefg", "abcdhfg" };
vector<string>strs2 = { "a","b","c" };


// 공통된 접두사중 가장 긴 접두사 찾기 
/*
string solution(vector <string> strs) {
	string answer = "";
	vector<string>imsi;


	for (int i = 0; i < strs[0].size(); i++) {
		for(int j=0;j<strs[0].size();j++
	}


	return answer;
}
*/
string solution (vector<string> strs) {
    string answer = "abc";
    if (strs.size() < 1) { return ""; }
    int i = 0;
    bool flag = false;
    while (i < strs[0].length() && !flag) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != c) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            i++;
        }
    }
    answer = strs[0].substr(0, i);
    return answer;
}




int main() {

    cout << solution(strs) << endl;

	return 0;
}