#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;






int main() {
    string a = "heloloo";
    if (a.find("o") != -1) {
        cout << "ok" << endl;
        cout << a.find("o") << endl;
        cout << a.find("oo") << endl;
    }
    else {
        cout << "nope" << endl;
    }


    return 0;
}