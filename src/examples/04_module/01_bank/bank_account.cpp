#include "bank_account.h"

//bank_account.cpp
int BankAccount::get_balance()const 
{ 
	return balance; 
}

void BankAccount::deposit(int amount)
{
	if (amount > 0) 
	{
		balance += amount;
	}
	else 
	{
		throw Invalid("Amount must be greater than 0.");
	}
}

void BankAccount::withdraw(int amount) 
{
	if (amount < 0) 
	{
		throw Invalid("Amount must be greater than 0.");
	}
	else if(amount > balance)
	{
		throw Invalid("Insufficient Funds");
	}
	else 
	{
		balance -= amount;
	}
}

void BankAccount::open(int amount)
{
	if (amount < min_balance_to_open) 
	{
		throw Invalid("Amount must be at least 25...");
	}

	balance += amount;
}

double BankAccount::rate = init_rate();

void display_balance(const BankAccount & b)
{
	std::cout << "Balance is: " << b.balance <<"\n";
}

std::ostream & operator<<(std::ostream & out, const BankAccount & b)
{
	out << "Balance is: " << b.balance<<"\n";

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	std::cout << "Enter amount: ";
	in >> amount;
	b.deposit(amount);
		
	return in;
}
