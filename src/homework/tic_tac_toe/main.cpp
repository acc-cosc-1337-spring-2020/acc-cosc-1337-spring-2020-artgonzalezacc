#include "tic_tac_toe.h"
#include<iostream>

using std::cout; using std::cin; using std::string;

int main() 
{
	string player = "Y";
	TicTacToe game;
	string cont;

	do
	{
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
			cout << "\nposition: \n";
			cin >> pos;
			game.mark_board(pos);
			game.display_board();
		} while (!game.game_over());

		cout << "\nWinner: " << game.get_winner()<<"\n";

		cout << "Enter Y to play again: ";
		cin >> cont;
	
	} while (cont == "Y");


	return 0;
}