//h
#include <string>
#include <vector>
#include<iostream>

class TicTacToe
{
public:
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player() const { return player; }
	std::string get_winner()const { return winner; }
	friend std::ostream& operator<<(std::ostream& out, const TicTacToe& t);
	friend std::istream& operator>>(std::istream& in, TicTacToe& t);
private:
	void set_next_player();
	bool check_board_full();
	void clear_board();
	bool check_row_win();
	bool check_column_win();
	bool check_diagonal_win();
	void set_winner();
	std::string player;
	std::string winner;
	std::vector<std::string> pegs{ 9, " " };
};

class Error
{
public:
	Error(std::string msg) : message{ msg } {};
	std::string get_message()const { return message; };
private:
	std::string message;
};