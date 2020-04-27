//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include<vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include<memory>

class TicTacToeManager
{
public:
	TicTacToeManager() = default;
	TicTacToeManager(TicTacToeData& data);
	void save_game(std::unique_ptr<TicTacToe>& game);
	friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& m);
	~TicTacToeManager();
private:
	void update_winner_count(std::string winner);
	std::vector<std::unique_ptr<TicTacToe>> games;
	TicTacToeData data;
	int o_wins{ 0 }, x_wins{ 0 }, ties{ 0 };
};

#endif // !TIC_TAC_TOE_MANAGER_H
