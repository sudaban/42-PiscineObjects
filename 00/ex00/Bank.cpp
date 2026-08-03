#include "Bank.hpp"

Bank::Bank()
{
	this->m_liquidity = 0;
	this->m_next_id = 0;
	this->m_database = std::map<int, Account*>();
}

Bank::Bank(const Bank& p_other)
{
	this->m_liquidity = p_other.m_liquidity;
	this->m_next_id = p_other.m_next_id;
	this->m_database = std::map<int, Account*>();
	for (std::map<int, Account*>::const_iterator it = p_other.m_database.begin(); it != p_other.m_database.end(); ++it)
		this->m_database[it->first] = new Account(*(it->second));
}

Bank& Bank::operator=(const Bank& p_other)
{
	if (this != &p_other)
	{
		for (std::map<int, Account*>::iterator it = this->m_database.begin(); it != this->m_database.end(); ++it)
			delete it->second;
		this->m_database.clear();

		this->m_liquidity = p_other.m_liquidity;
		this->m_next_id = p_other.m_next_id;
		for (std::map<int, Account*>::const_iterator it = p_other.m_database.begin(); it != p_other.m_database.end(); ++it)
			this->m_database[it->first] = new Account(*(it->second));
	}
	return *this;
}

Bank::~Bank()
{
	for (std::map<int, Account*>::iterator it = this->m_database.begin(); it != this->m_database.end(); ++it)
		delete it->second;
	this->m_database.clear();
}

const char* Bank::AccountNotFoundException::what() const throw()
{
	return "Account not found";
}

const char* Bank::InvalidAmountException::what() const throw()
{
	return "Invalid amount (must be positive)";
}

const char* Bank::InsufficientFundsException::what() const throw()
{
	return "Insufficient funds in account";
}

const char* Bank::BankInsufficientLiquidityException::what() const throw()
{
	return "Bank has insufficient liquidity for this loan";
}

int const& Bank::m_liquidity_getter() const
{
	return this->m_liquidity;
}

int Bank::m_account_count_getter() const
{
	return static_cast<int>(this->m_database.size());
}

Account& Bank::operator[](int p_id)
{
	std::map<int, Account*>::iterator it = this->m_database.find(p_id);
	if (it == this->m_database.end())
		throw Bank::AccountNotFoundException();
	return *(it->second);
}

void Bank::CreateAccount(int p_initial_deposit)
{
	if (p_initial_deposit <= 0)
		throw Bank::InvalidAmountException();

	int var_fee = (p_initial_deposit * 5) / 100;
	int var_amount = p_initial_deposit - var_fee;

	Account* var_new_account = new Account(this->m_next_id, var_amount);
	this->m_database[this->m_next_id] = var_new_account;
	this->m_next_id++;

	this->m_liquidity += var_fee;
}

void Bank::DeleteAccount(int p_id)
{
	std::map<int, Account*>::iterator it = this->m_database.find(p_id);
	if (it == this->m_database.end())
		throw Bank::AccountNotFoundException();

	this->m_liquidity += it->second->m_value;
	delete it->second;
	this->m_database.erase(it);
}

void Bank::Deposit(int p_id, int p_amount)
{
	if (p_amount <= 0)
		throw Bank::InvalidAmountException();

	std::map<int, Account*>::iterator it = this->m_database.find(p_id);
	if (it == this->m_database.end())
		throw Bank::AccountNotFoundException();

	int var_fee = (p_amount * 5) / 100;
	int var_amount = p_amount - var_fee;

	it->second->m_value += var_amount;
	this->m_liquidity += var_fee;
}

void Bank::Withdraw(int p_id, int p_amount)
{
	if (p_amount <= 0)
		throw Bank::InvalidAmountException();

	std::map<int, Account*>::iterator it = this->m_database.find(p_id);
	if (it == this->m_database.end())
		throw Bank::AccountNotFoundException();

	if (p_amount > it->second->m_value)
		throw Bank::InsufficientFundsException();

	it->second->m_value -= p_amount;
	this->m_liquidity += p_amount;
}

void Bank::Loan(int p_id, int p_amount)
{
	if (p_amount <= 0)
		throw Bank::InvalidAmountException();

	std::map<int, Account*>::iterator it = this->m_database.find(p_id);
	if (it == this->m_database.end())
		throw Bank::AccountNotFoundException();

	if (p_amount > this->m_liquidity)
		throw Bank::BankInsufficientLiquidityException();

	it->second->m_value += p_amount;
	this->m_liquidity -= p_amount;
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "===== Bank Information =====" << std::endl;
	p_os << "Liquidity : " << p_bank.m_liquidity << std::endl;
	p_os << "Account count : " << p_bank.m_database.size() << std::endl;
	p_os << "Accounts :" << std::endl;
	for (std::map<int, Account*>::const_iterator it = p_bank.m_database.begin(); it != p_bank.m_database.end(); ++it)
		p_os << "  " << *(it->second) << std::endl;
	return p_os;
}
