#ifndef BANK_HPP
# define BANK_HPP

#include <map>
#include <iostream>
#include "Account.hpp"

class Bank
{
private:
	int m_liquidity;
	int m_next_id;
	std::map<int, Account*> m_database;

public:
	Bank();
	~Bank();

	Bank(const Bank& p_other);
	Bank& operator=(const Bank& p_other);

	int const& m_liquidity_getter() const;
	int m_account_count_getter() const;

	Account& operator[](int p_id);

	void CreateAccount(int p_initial_deposit);
	void DeleteAccount(int p_id);
	void Deposit(int p_id, int p_amount);
	void Withdraw(int p_id, int p_amount);
	void Loan(int p_id, int p_amount);

	class AccountNotFoundException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidAmountException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InsufficientFundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class BankInsufficientLiquidityException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
};

#endif
