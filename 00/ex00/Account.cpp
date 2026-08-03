#include "Account.hpp"

Account::Account()
{
	this->m_id = -1;
	this->m_value = 0;
}

Account::Account(int m_id, int m_value)
{
	this->m_id = m_id;
	this->m_value = m_value;
}

Account::~Account() {}

int const& Account::m_id_getter() const
{
	return this->m_id;
}

int const& Account::m_value_getter() const
{
	return this->m_value;
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	p_os << "[id: " << p_account.m_id << "] - [value: " << p_account.m_value << "]";
	return p_os;
}
