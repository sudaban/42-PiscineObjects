/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:45:41 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/11 11:33:27 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#include <iostream>
#include <vector>

class Account
{
private:
	int m_id;
	int m_value;

public:
	Account();
	Account(int m_id, int m_value);
	~Account();
	
	int const& get_id() const;
	int const& get_value() const;
	
	void set_value(int amount);
	void add_to_value(int amount);
	
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
	friend class Bank;
};

#endif // ACCOUNT_HPP