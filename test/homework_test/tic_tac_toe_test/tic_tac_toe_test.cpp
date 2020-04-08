#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game")
{

	TicTacToe game;
	REQUIRE_THROWS_AS(game.mark_board(1), Error);
}

TEST_CASE("Test start game accepts only X or O")
{

	TicTacToe game;
	REQUIRE_THROWS_AS(game.start_game("Y"), Error);
}

TEST_CASE("Test set first player to X")
{

	TicTacToe game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set first player to O")
{

	TicTacToe game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{

	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");

	game.mark_board(4);
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game ends when board is full") 
{
	TicTacToe game;
	game.start_game("X");

	for (int i = 1; i < 9; ++i) 
	{
		game.mark_board(i);
		REQUIRE(game.game_over() == false);
	}

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}
