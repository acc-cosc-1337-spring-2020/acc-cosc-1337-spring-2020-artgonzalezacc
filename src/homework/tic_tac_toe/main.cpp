#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<iostream>
#include<functional>

using std::cout; using std::cin; using std::string;

int main() 
{
	std::unique_ptr<TicTacToeManager> manager = std::make_unique< TicTacToeManager>();
	string cont;

	do
	{
		int game_type;
		cout << "\nTictactoe 3 or 4?";
		cin >> game_type;
		std::unique_ptr<TicTacToe> game;

		if (game_type == 3) 
		{
			game = std::make_unique<TicTacToe3>();
		}
		else if(game_type == 4) 
		{
			game = std::make_unique<TicTacToe4>();
		}

		string player = "Y";

		while (!(player == "O" || player == "X"))
		{
			try
			{
				cout << "Enter player: ";
				cin >> player;

				game->start_game(player);
			}
			catch (Error e)
			{
				cout << e.get_message();
			}
		}

		int choice = 1;

		do
		{
			try
			{
				cin >> *game;
				cout << *game;
			}
			catch (Error e)
			{
				cout << e.get_message();
			}

		} while (!game->game_over());

		cout << "\nWinner: " << game->get_winner() << "\n";

		manager->save_game(game);

		cout << "Enter Y to play again: ";
		cin >> cont;
	
	} while (cont == "Y");

	cout << *manager;

	return 0;
}