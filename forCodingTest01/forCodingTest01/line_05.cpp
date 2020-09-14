#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void init();

vector<int> cards = { 10, 13, 10, 1, 2, 3, 4, 5, 6, 2 };
int deal_hide = 0;
int deal_show = 0;
int player_point = 0;

int money = 0;

void check(int n) {
	int deal_ret;

	if (deal_show == 1) {
		if (deal_hide + 11 > 17) {
			deal_ret = deal_hide + 1;
		}
		else {
			deal_ret = deal_hide + 11;
		}
	}
	

	else if (deal_hide == 1) {
		if (deal_show + 11 > 17) {
			deal_ret = deal_show + 1;
		}
		else {
			deal_ret = deal_show + 11;
		}
	}
	else {
		deal_ret = deal_show + deal_hide;
	}
	
	
	
	
	
	for (int i = n; i <= (int)cards.size(); i++) {
		cout << "µô·¯ ÃÑÁ¡¼ö :" << deal_ret << endl;
		cout << i << endl;
		// µô·¯ÆÐ
		if (deal_ret > 21) {
			if (player_point == 21) {
				money += 3;
				return;
			}
			else {
				money += 2;
				return;
			}
		}

		// °è¼Ó ¹Þ±â
		else {
			if (deal_ret < 17) {


				if (cards[i] == 1 && deal_ret + 11 > 17) {
					deal_ret += 1;
					continue;
				}
				else if (cards[i] == 1) {
					deal_ret += 11;
					continue;
				}
				else {
					deal_ret += cards[i];
					continue;
				}

			}
			else {// 17 18 19 20
				// ºñ±³
				deal_ret += cards[i];

			}
		}
		if (i == cards.size()-1) {
			if (deal_ret > 21) {
				money -= 2;
				return;
			}
			else {
				if (player_point > deal_ret) {//ÇÃ·¹ÀÌ¾î½Â
					money += 2;
					return;
				}
				else if (player_point < deal_ret) {
					//µô·¯½Â
					money -= 2;
					return;
				}
				else {
					money = 0;
					return;
				}
			}
		}
	}
	
}

void solution(vector<int> cards) {
	int answer = -1;



	for (int i = 0; i < (int)cards.size(); i++) {
		if (i == 0) {
			if (cards[i] >= 10)player_point += 10;
			else player_point += cards[i];
			continue;
		}
		if (i == 1) {
			deal_hide = cards[i];
			continue;
		}
		if (i == 2) {
			if (cards[i] >= 10)player_point += 10;
			else player_point += cards[i];
			continue;
		}
		if (i == 3) {
			deal_show = cards[i];
			continue;
		}

		cout << "----------------" << endl;
		cout << "ÅÏ :" << i << endl;
		cout << "ÇÃ·¹ÀÌ¾î :" << player_point << endl;
		cout << "µô·¯ º¸ÀÌ±â :" << deal_show << endl;
		cout << "µô·¯ Á¡¼ö :" << deal_hide << endl;


		if (player_point == 21) {
			check(i);
			return;
		}
		// ¹ÞÀ»¶§
		if (player_point < 21) {
			
			if (deal_show == 1 || deal_show >= 7) {
				if (player_point < 17) {
					if (cards[i] == 1 && player_point+11>17) {
						player_point += 1;
					}
					else if (cards[i] == 1) {
						player_point += 11;
					}
					else {
						player_point += cards[i];
					}
				}
				else {
					check(i);
					return;
				}
			}
			if (deal_show == 4 || deal_show == 5 || deal_show == 6) {
				check(i);
				return;
			}
			if (deal_show == 2 || deal_show == 3) {
				if (player_point < 12) {
					player_point += cards[i];
				}
				else {
					check(i);
					return;
				}
			}
		}
		if (player_point > 21) {
			money = money - 2;
			return;
		}
	}
}

int main() {
	init();
	solution(cards);
	cout << money << endl;
	return 0;
}
void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
}