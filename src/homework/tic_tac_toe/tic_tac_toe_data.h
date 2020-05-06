//h
#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<fstream>
#include<memory>
#include<string>
#include<vector>

class TicTacToeData 
{
public:
	void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
	std::vector<std::unique_ptr<TicTacToe>> get_games();
private:
	const std::string file_name{ "tic_tac_toe.dat" };

};


#endif // !TIC_TAC_TOE_DATA_H