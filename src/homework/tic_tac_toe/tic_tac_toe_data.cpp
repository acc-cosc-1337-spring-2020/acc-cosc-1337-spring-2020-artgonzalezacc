#include "tic_tac_toe_data.h"

//cpp
using std::vector;	using std::string; using std::unique_ptr; using std::make_unique;

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);

	for (auto& game : games) 
	{
		for (auto peg : game->get_pegs()) 
		{
			file_out << peg;
		}

		file_out << game->get_winner();
		file_out << "\n";
	}

	file_out.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	std::ifstream read_file (file_name);
	vector<unique_ptr<TicTacToe>> games;

	unique_ptr<TicTacToe> game;
	string line;

	if (read_file.is_open())
	{

		while (getline(read_file, line)) 
		{
			vector<string> pegs;

			for (size_t i = 0; i < line.size()-1; ++i) 
			{
				pegs.push_back(string(1, line[i]));
			}
			
			if (pegs.size() == 9) 
			{
				game = make_unique<TicTacToe3>(pegs, string(1, line.back()));
			}
			else if (pegs.size() == 16)
			{
				game = make_unique<TicTacToe4>(pegs, string(1, line.back()));
			}
			
			games.push_back(std::move(game));
		}

		read_file.close();
	}

	return games;
}
