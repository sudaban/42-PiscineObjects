#include "Bank.hpp"

Bank::Bank()
{
	this->m_liquidity = 0;
	this->m_database = std::vector<Account *>();
	this->m_next_id = 0;
}

Bank::~Bank()
{
	for (std::vector<Account *>::iterator it = this->m_database.begin(); it != this->m_database.end(); ++it) {
		delete *it;
	}
	this->m_database.clear();
}

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.m_liquidity << std::endl;
	
	typedef std::vector<Account *>::const_iterator it_type;
	for (it_type it = p_bank.m_database.begin(); it != p_bank.m_database.end(); ++it)
		p_os << **it << std::endl;
	
	return (p_os);
}

int const& Bank::get_liquidity() const {
	return this->m_liquidity;
}

Account *Bank::get_account_by_id(int id) const {
	for (std::vector<Account *>::const_iterator it = this->m_database.begin(); it != this->m_database.end(); ++it) {
		if ((*it)->get_id() == id) {
			return *it;
		}
	}
	return NULL;
}

bool Bank::create_account(int initial_deposit) {
	if (initial_deposit <= 0) {
		std::cout << "Cannot create account with negative or zero deposit" << std::endl;
		return false;
	}
	
	Account *new_account = new Account(this->m_next_id++, initial_deposit);
	this->m_database.push_back(new_account);
	
	// Bank gets 5% of the deposit
	int bank_fee = initial_deposit * 5 / 100;
	int account_amount = initial_deposit - bank_fee;
	
	new_account->set_value(account_amount);
	this->m_liquidity += bank_fee;
	
	std::cout << "Account created with id: " << new_account->get_id() << std::endl;
	std::cout << "Deposit: " << initial_deposit << " (5% fee: " << bank_fee << ")" << std::endl;
	
	return true;
}

bool Bank::delete_account(int id) {
	for (std::vector<Account *>::iterator it = this->m_database.begin(); it != this->m_database.end(); ++it) {
		if ((*it)->get_id() == id) {
			this->m_liquidity += (*it)->get_value();
			delete *it;
			this->m_database.erase(it);
			std::cout << "Account with id " << id << " deleted" << std::endl;
			return true;
		}
	}
	std::cout << "No account found with id: " << id << std::endl;
	return false;
}

bool Bank::deposit(int id, int amount) {
	if (amount <= 0) {
		std::cout << "Cannot deposit negative or zero amount" << std::endl;
		return false;
	}
	
	Account *account = this->get_account_by_id(id);
	if (account == NULL) {
		std::cout << "No account found with id: " << id << std::endl;
		return false;
	}
	
	// Bank gets 5% of the deposit
	int bank_fee = amount * 5 / 100;
	int account_amount = amount - bank_fee;
	
	account->add_to_value(account_amount);
	this->m_liquidity += bank_fee;
	
	std::cout << "Deposit of " << amount << " to account " << id << " (5% fee: " << bank_fee << ")" << std::endl;
	
	return true;
}

bool Bank::withdraw(int id, int amount) {
	if (amount <= 0) {
		std::cout << "Cannot withdraw negative or zero amount" << std::endl;
		return false;
	}
	
	Account *account = this->get_account_by_id(id);
	if (account == NULL) {
		std::cout << "No account found with id: " << id << std::endl;
		return false;
	}
	
	if (amount > account->get_value()) {
		std::cout << "Not enough funds to withdraw " << amount << std::endl;
		return false;
	}
	
	account->add_to_value(-amount);
	this->m_liquidity += amount;
	
	std::cout << "Withdrawal of " << amount << " from account " << id << std::endl;
	
	return true;
}

bool Bank::loan(int id, int amount) {
	if (amount <= 0) {
		std::cout << "Cannot give negative or zero loan" << std::endl;
		return false;
	}
	
	Account *account = this->get_account_by_id(id);
	if (account == NULL) {
		std::cout << "No account found with id: " << id << std::endl;
		return false;
	}
	
	if (amount > this->m_liquidity) {
		std::cout << "Bank doesn't have enough funds for loan of " << amount << std::endl;
		return false;
	}
	
	account->add_to_value(amount);
	this->m_liquidity -= amount;
	
	std::cout << "Loan of " << amount << " given to account " << id << std::endl;
	
	return true;
}