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

	//1. attr 1���� (0, 1, 2, 3)
		//1-1. 0���� �ߺ�üũ
			// ������ �ϳ��� ������ break; (�ش� Ű�� ���Ұ�)
			// �� �ٸ��� -> �ĺ�Ű cnt++ ���ְ� ������ ���ϴ°ſ��� '�й�' �� ������

		//1-2. 1���� ��
		//1-3. 2���� ��
		//1-4. 3���� ��



	//2. attr 2���� ((01, 02, 03, 12, 13, 23) ��, 1. ���� ���� attr�� ���� 
		//2-1. 01  �ߺ�üũ
			//




	//3. attr 3���� (012, 013, 123)
	//4. attr attr_num(4)���� (0123)
	




	return answer;
}


int main() {


	solution(relation);

	return 0;
}