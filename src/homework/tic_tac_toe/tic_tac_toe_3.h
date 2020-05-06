//h
#ifndef TIC_TAC_TOE_3
#define TIC_TAC_TOE_3
#include "tic_tac_toe.h"
#include<string>
#include<vector>

class TicTacToe3 : public TicTacToe
{
public:
	TicTacToe3() : TicTacToe(3) {}
	TicTacToe3(std::vector<std::string> p, std::string winner) : TicTacToe(p, winner) {}
private:
	bool check_column_win() override;
	bool check_row_win() override;
	bool check_diagonal_win() override;

};

#endif // !TIC_TAC_TOE_3