#include "tic_tac_toe_manager.h"

//cpp

void TicTacToeManager::save_game(TicTacToe game)
{
	games.push_back(game);
}

void TicTacToeManager::update_winner_count(std::string winner)
{
	if (winner == "X") 
	{
		x_wins++;
	}
	else if(winner == "O") 
	{
		o_wins++;
	}
	else 
	{
		ties++;
	}
}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & m)
{
	out << "\n";
	for (auto game : m.games) 
	{
		out << game<<"\n";
	}

	out << "\nO wins: " << m.o_wins<<"\n";
	out << "X wins: " << m.x_wins<<"\n";
	out << "Ties: " << m.ties<<"\n";

	return out;
}
