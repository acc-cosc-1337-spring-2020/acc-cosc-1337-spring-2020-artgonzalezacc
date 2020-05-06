
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify TicTacToe mark board function")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	REQUIRE_THROWS_AS(game3->mark_board(1), Error);
}

TEST_CASE("Verify TicTacToe start game function")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	REQUIRE_THROWS_AS(game3->start_game("A"), Error);
}

TEST_CASE("Verify TicTacToe set first player function X")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");

	REQUIRE(game3->get_player() == "X");
}

TEST_CASE("Verify TicTacToe set first player function O")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("O");

	REQUIRE(game3->get_player() == "O");
}

TEST_CASE("Verify TicTacToe test game flow O")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->get_player() == "X");

	game3->mark_board(4);
	REQUIRE(game3->get_player() == "O");

}

TEST_CASE("Verify TicTacToe test game flow X")
{
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("O");
	REQUIRE(game3->get_player() == "O");

	game3->mark_board(4);
	REQUIRE(game3->get_player() == "X");

}

TEST_CASE("Win by first column") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(4);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);//X
	//X wins
	REQUIRE(game3->game_over() == true);
	REQUIRE(game3->get_winner() == "X");
}

TEST_CASE("Win by second column") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(8);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by third column") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(6);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(9);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by first row") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(4);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by second row") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(4);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(9);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(6);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by third row") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(8);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(9);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by diagonally top left") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(9);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Win by diagonally bottom left") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);//X
	//X wins
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("For no Winner") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE(game3->game_over() == false);
	game3->mark_board(2);//X        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(1);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(5);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(3);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(7);//X
	REQUIRE(game3->game_over() == false);
	game3->mark_board(4);//O        
	REQUIRE(game3->game_over() == false);
	game3->mark_board(6);//X          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(8);//O          
	REQUIRE(game3->game_over() == false);
	game3->mark_board(9);//X          
	REQUIRE(game3->game_over() == true);
}

TEST_CASE("Mark position") {
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
	game3->start_game("X");
	REQUIRE_THROWS_AS(game3->mark_board(0), Error);
	REQUIRE_THROWS_AS(game3->mark_board(10), Error);
	game3->mark_board(5);

}







TEST_CASE("Verify TicTacToe mark board function4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	REQUIRE_THROWS_AS(game4->mark_board(1), Error);
}

TEST_CASE("Verify TicTacToe start game function4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	REQUIRE_THROWS_AS(game4->start_game("A"), Error);
}

TEST_CASE("Verify TicTacToe set first player function X4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");

	REQUIRE(game4->get_player() == "X");
}

TEST_CASE("Verify TicTacToe set first player function O4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("O");

	REQUIRE(game4->get_player() == "O");
}

TEST_CASE("Verify TicTacToe test game flow O4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->get_player() == "X");

	game4->mark_board(4);
	REQUIRE(game4->get_player() == "O");

}

TEST_CASE("Verify TicTacToe test game flow X4")
{
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("O");
	REQUIRE(game4->get_player() == "O");

	game4->mark_board(4);
	REQUIRE(game4->get_player() == "X");

}

TEST_CASE("Win by first column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->game_over() == true);
	REQUIRE(game4->get_winner() == "X");
}

TEST_CASE("Win by second column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by third column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}
TEST_CASE("Win by fourth column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by first row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by second row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by third row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}
TEST_CASE("Win by fourth row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by diagonally top left4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by diagonally bottom left4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("For no Winner4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//O        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Mark position4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE_THROWS_AS(game4->mark_board(0), Error);
	REQUIRE_THROWS_AS(game4->mark_board(17), Error);
	game4->mark_board(5);

}


