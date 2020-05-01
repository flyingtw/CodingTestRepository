#include <string>
#include <vector>
#include <iostream>


using namespace std;


vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
vector<string> banned_id1 = { "fr*d*", "abc1**" };
vector<string> banned_id2 = { "*rodo", "*rodo", "******" };
vector<string> banned_id3 = { "fr*d*", "*rodo", "******", "******" };

string aaa = "abc123";
string bbb = "abc1**";
string ccc = "***";
string ddd = "dgg";

// 두 글자가 가능한지 비교하는 함수
bool isSame(string a, string b, int a_num, int b_num) {
    bool flag = false;
    for (int i = 0; i < a_num; i++) {
        if (a_num != b_num) break;
        if (a[i] == b[i] || b[i] == '*') {
            if (i + 1 == a_num) {
                flag = true;
            }
            continue;
        }
        if (a[i] != b[i]) {
            break;
        }
    }
    return flag;
}
void Print(vector<string> user_id) {

    for (int i = 0; i < user_id.size(); i++) {

        cout << user_id[i] << " ";
    }
    cout << endl;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    vector<vector<string>>fit;

    while (user_id.size() != 0) {
        cout << "시작" << endl;
        cout << "user :";
        Print(user_id);
        cout << "banned :";
        Print(banned_id);


        for (int i = 0; i < banned_id.size(); i++) {
            //i=0 frodo
            vector<string>imsi;
            int ban_word_n = banned_id[i].size();

            for (int j = 0; j < user_id.size(); j++) {
                int word_n = user_id[j].size();//5      


                if (isSame(user_id[j], banned_id[i], word_n, ban_word_n)) {
                    cout << "banned_id[i] :" << banned_id[i] << endl;
                    cout << "user_id[j] :" << user_id[j] << endl;
                    cout << isSame(user_id[j], banned_id[i], word_n, ban_word_n) << endl;
                    cout << "---------------------------------------------" << endl;
                    imsi.push_back(user_id[j]);
                    //user_id.erase(user_id.begin() + j);
                    break;
                }

                /*
                cout << "banned_id[i] :" << banned_id[i] << endl;
                cout << "user_id[j] :" << user_id[j] << endl;
                cout << isSame(user_id[j], banned_id[i], word_n, ban_word_n) << endl;
                cout << "---------------------------------------------" << endl;
                */
            }
            fit.push_back(imsi);
            imsi.clear();
        }
    }

    /*
    for (int i = 0; i < fit.size(); i++) {
        cout << "------------" << endl;
        for (int j = 0; j < fit[i].size(); j++) {
            cout << fit[i][j] << " ";
        }

    }
    */

    //cout << isSame(aaa, bbb, aaa.length(), bbb.length()) << endl;

    return answer;
}



int main() {
    /*
    vector<int>test = { 1,2,3,4,5 };
    test.erase(test.begin() + 2);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << endl;
    }
     vector<vector<string>> a;
    a.push_back({ "aaa","bbb","ccc" });
    a.push_back({ "ddd","eee" });

    cout << a[0][0] << endl;
    cout << a[0][1] << endl;
    cout << a[0][2] << endl;
    cout << a[1][0] << endl;
    */

    //solution(user_id, banned_id3);
    //vector<int, vector<string>> a = make_pair(1, { "abc","asdf" });
    //vector<int, vector<string> > a = { make_pair(1, {"asd","asdf"}), make_pair(2,{"sex","sibal"}) };



    return 0;
}