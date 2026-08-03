#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#include <iostream>

class Bank;

class Account
{
private:
	int m_id;
	int m_value;

	Account(int m_id, int m_value);

public:
	Account();
	~Account();

	int const& m_id_getter() const;
	int const& m_value_getter() const;

	friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);
	friend class Bank;
};

#endif
