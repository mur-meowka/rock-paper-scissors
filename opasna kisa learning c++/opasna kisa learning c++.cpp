#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
bool has_user_won(int user_choose, int random_choose, int result) {
	bool is_user_smaller = user_choose < random_choose;
	return result == 1 && is_user_smaller || result == 2 && !is_user_smaller;
}

bool check_user_input(int user_choose) {
	if (user_choose < 1) {
		return false;
	}

	if (user_choose > 3) {
		return false;
	}

	return true;
}

int game()
{
	srand(time(NULL));
	string game_items[3] = { "rock", "scissors", "paper" };
	int user_choose = NULL;
	int random_choose;
	// user_choose < 0 || user_choose > 2
	while (!check_user_input(user_choose)) {
		cout << "Enter your choose:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << game_items[i] << endl;
		}
		cin >> user_choose;
	}
	int user_item = user_choose - 1;
	random_choose = rand()%3;
	cout << "user chose: " << game_items[user_item] << endl << "program chose: " << game_items[random_choose] << endl;
	int result = abs(user_item - random_choose);
	if (result == 0) {
		cout << "draw" << endl;
		return 0;
	}
	if (has_user_won(user_item, random_choose, result )) {
		cout << "user has won" << endl;
		return 0;
	}
	cout << "user lost" << endl;
}

int main() {
	string play_again = "yes";
	while (play_again == "yes") {
		game();
		cout << "do you want play again? (yes/no)" << endl;
		cin >> play_again;
	}
}