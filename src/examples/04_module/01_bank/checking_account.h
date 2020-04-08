//checking_account.h
#include "bank_account.h"

class CheckingAccount : public BankAccount
{
public:
	CheckingAccount() = default;
	explicit CheckingAccount(int b) : BankAccount(b) { }
	int get_balance()const { return balance * (1 + get_rate()); }
};