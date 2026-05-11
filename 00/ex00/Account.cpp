#include "Account.hpp"

Account::Account() {
	this->m_id = -1;
	this->m_value = 0;
}

Account::Account(int m_id, int m_value) {
	this->m_id = m_id;
	this->m_value = m_value;
}

Account::~Account() {}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.m_id << "] - [" << p_account.m_value << "]";
	return (p_os);
}

int const& Account::get_id() const {
	return this->m_id;
}

int const& Account::get_value() const {
	return this->m_value;
}

void Account::set_value(int amount) {
	this->m_value = amount;
}

void Account::add_to_value(int amount) {
	this->m_value += amount;
}