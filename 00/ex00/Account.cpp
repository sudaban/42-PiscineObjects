#include "Account.hpp"

Account::Account() {
	this->m_id = -1;
	this->m_value = 0;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.m_id << "] - [" << p_account.m_value << "]";
	return (p_os);
}