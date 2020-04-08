#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <memory>
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"

using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test BankAccount constructor") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(90);

	REQUIRE(account->get_balance() == 500);
}

TEST_CASE("Test Bank account deposit") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(500);
	REQUIRE(account->get_balance() == 500);

	account->deposit(50);
	REQUIRE(account->get_balance() == 550);

	REQUIRE_THROWS_AS(account->deposit(-50), Invalid);
	REQUIRE(account->get_balance() == 550);
}

TEST_CASE("Test BankAccount withdraw") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>(500);
	REQUIRE(account->get_balance() == 500);

	account->withdraw(50);
	REQUIRE(account->get_balance() == 450);

	REQUIRE_THROWS_AS(account->withdraw(-1), Invalid);
	REQUIRE(account->get_balance() == 450);

	REQUIRE_THROWS_AS(account->withdraw(451), Invalid);
	REQUIRE(account->get_balance() == 450);

}

TEST_CASE("Test BankAccount default constuctor balance 0") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>();
	REQUIRE(account->get_balance() == 0);
}

TEST_CASE("Test BankAccount initial open deposit >= 25") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>();
	REQUIRE(account->get_balance() == 0);
	
	account->open(25);
	REQUIRE(account->get_balance() == 25);
}

TEST_CASE("Test BankAccount initial open deposit < 25") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>();
	REQUIRE(account->get_balance() == 0);

	REQUIRE_THROWS_AS(account->open(24), Invalid);
}

TEST_CASE("Test BankAccount static rate initialization") 
{
	unique_ptr<BankAccount> account = make_unique<SavingsAccount>();

	REQUIRE(account->get_rate() == 0.025);
}

TEST_CASE("Test CheckingAccount constructor")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(500);

	REQUIRE(account->get_balance() == 512);
}

TEST_CASE("Test CheckingAccount get balance")
{
	unique_ptr<BankAccount> account = make_unique<CheckingAccount>(500);
	REQUIRE(account->get_balance() == 153);
}

