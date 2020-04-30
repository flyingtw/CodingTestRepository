#include <iostream>
#include <vector>
#include <string>


using namespace std;


									//0      1       2        3
vector<vector<string>> relation = { {"100", "ryan", "music", "2"}, //r[0]
									{"200", "apeach", "math", "2"}, //r[1]
									{"300", "tube", "computer", "3"}, //r[2]
									{"400", "con", "computer", "4"}, //r[4]
									{"500", "muzi", "music", "3"}, //r[5]
									{"600", "apeach", "music", "2"} };//r[6]

int solution(vector<vector<string>> r) {
	int answer = 0;
	int tuple_num = r.size();//6
	int attr_num = r[0].size();//4

	//1. attr 1개씩 (0, 1, 2, 3)
		//1-1. 0끼리 중복체크
			// 같은게 하나라도 있으면 break; (해당 키는 사용불가)
			// 다 다르다 -> 후보키 cnt++ 해주고 앞으로 비교하는거에서 '학번' 을 빼버림

		//1-2. 1끼리 비교
		//1-3. 2끼리 비교
		//1-4. 3끼리 비교



	//2. attr 2개씩 ((01, 02, 03, 12, 13, 23) 단, 1. 에서 사용된 attr은 빼기 
		//2-1. 01  중복체크
			//




	//3. attr 3개씩 (012, 013, 123)
	//4. attr attr_num(4)개씩 (0123)
	




	return answer;
}


int main() {


	solution(relation);

	return 0;
}