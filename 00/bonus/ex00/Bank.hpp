#ifndef BANK_HPP
# define BANK_HPP

#include <map>
#include <iostream>

class Bank
{
private:
	class Account
	{
		private:
			int m_id;
			int m_value;

		public:
			Account();
			Account(int p_id, int p_value);
			Account(const Account& p_other);
			Account& operator=(const Account& p_other);
			~Account();

			int const& GetId() const;
			int const& GetValue() const;

			friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
			friend class Bank;
	};

	int m_liquidity;
	int m_next_id;
	std::map<int, Account*> m_database;

public:
	Bank();
	~Bank();

	Bank(const Bank& p_other);
	Bank& operator=(const Bank& p_other);

	int const& GetLiquidity() const;
	int GetAccountCount() const;

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
	friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
};

#endif
