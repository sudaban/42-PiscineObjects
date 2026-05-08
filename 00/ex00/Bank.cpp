#include "Bank.hpp"

Bank::Bank()
{
	this->m_liquidity = 0;
	this->m_client_accounts = std::vector<Account *>();
}

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.m_liquidity << std::endl;
	
	typedef std::vector<Account *>::const_iterator it_type;
	for (it_type it = p_bank.m_client_accounts.begin(); it != p_bank.m_client_accounts.end(); ++it)
		p_os << **it << std::endl;
	
	return (p_os);
}

int Bank::get_liquidity() const {
	return this->m_liquidity;
}

std::vector<Account *> Bank::get_client_accounts() const {
	return this->m_client_accounts;
}