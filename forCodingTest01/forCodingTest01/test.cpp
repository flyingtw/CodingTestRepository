#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int main() {

	string imsi = "abc";
	char c = imsi[0];
	char cc = imsi[1];
	string s;
	s.push_back(c);
	s.push_back(cc);
	cout << s << endl;
	

	return 0;
}
