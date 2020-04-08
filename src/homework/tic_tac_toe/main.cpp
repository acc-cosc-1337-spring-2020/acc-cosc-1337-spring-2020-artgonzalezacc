#include "tic_tac_toe.h"
#include<iostream>

using std::cout; using std::cin; using std::string;

int main() 
{
	string player = "Y";
	TicTacToe game;

	while (!(player == "O" || player == "X")) 
	{
		try 
		{
			cout << "Enter player: ";
			cin >> player;

			game.start_game(player);
		}
		catch (Error e) 
		{
			cout << e.get_message();
		}
	}

	int choice = 1;

	do 
	{
		int pos;
		cout << "position: ";
		cin >> pos;
		game.mark_board(pos);

		cout << "continue";
		cin >> choice;
	} while (choice == 1);


	return 0;
}