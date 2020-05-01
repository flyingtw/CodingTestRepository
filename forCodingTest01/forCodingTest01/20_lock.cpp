#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
vector<vector<int>> small_key = { {0, 0}, {1, 0} };
vector<vector<int>> small_lock = { {0, 0}, {1, 0} };
vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

// key : M (3<=M<=20)
// lock : N (3<=N<=20)
// M<=N (열쇠는 항상 작거나 같다)





// 90도로 한방향 돌리기
vector<vector<int>> rotate(vector<vector<int>> &arr) {
	int m = arr.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = arr[m - j - 1][i];
		}
	}
	return temp;
}

void Print(vector<vector<int>> arr) {
	
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------" << endl;
}
bool compare(vector<vector<int>> key, vector<vector<int>> lock) {
	bool flag = true;
	
	// key 랑 lock 비교해서 lock은 0, key는 1이면 1로 바꿈
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			if (lock[i][j] == 0 && key[i][j] == 1) {
				lock[i][j] = 1;
			}
		}
	}

	// lock 배열 전부 1인지 체크
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			if (lock[i][j] == 0)return false;
			
			
		}
	}
	
	return flag;
}
bool compare2(vector<vector<int>> key2, vector<vector<int>> lock2, int lock_i, int lock_j) {
	bool flag = false;
	int key_size = key2.size();//3
	for (int i = 0; i < key_size; i++) {
		for (int j = 0; j < key_size; j++) {
			//3x3 비교
			if (lock2[lock_i][lock_j] == 0 && key[i][j] == 1) {
				lock2[lock_i][lock_j] = 1;
			}
			lock_j++;
		}
		lock_i++;
	}
	return flag;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	
	vector<vector<int>> key1=rotate(key);
	vector<vector<int>> key2 = rotate(key1);
	vector<vector<int>> key3 = rotate(key2);
	

	
	// lock 배열 key 범위만큼 확장하기
	int key_size = key.size();
	int ori_lock_size = lock.size();
	vector<vector<int>> new_lock(ori_lock_size+(key_size)*2-2, vector<int>(ori_lock_size + (key_size) * 2 - 2, 0));
	//Print(new_lock);
	for (int i = key_size - 1; i < key_size+ori_lock_size-1; i++) {
		for (int j = key_size - 1; j < key_size + ori_lock_size - 1; j++) {
			new_lock[i][j] = lock[i - key_size+1][j - key_size+1];
		}
	}
	Print(new_lock);
	/* =>  이부분 하나하나 가면서 비교하는게 안됨
	for (int i = 0; i < new_lock.size()-1; i++) {
		for (int j = 0; j < new_lock.size()-1; i++) {
			for (int a = 0; a < key.size(); a++) {
				for (int b = 0; b < key.size(); b++) {
					if(key[a][b]==1 && )
				}
			}
		}
	}
	*/





	
	return answer;
}

int main() {


	cout<<solution(key, lock)<<endl;

	
	return 0;
}