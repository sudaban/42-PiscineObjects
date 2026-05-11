/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:44:33 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/11 11:33:27 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP

#include <vector>
#include <iostream>
#include "Account.hpp"

class Bank
{
private:
	int m_liquidity;
	std::vector<Account *> m_database;
	int m_next_id;
	
public:
	Bank();
	~Bank();
	
	int const& get_liquidity() const;
	Account *get_account_by_id(int id) const;
	
	bool create_account(int initial_deposit);
	bool delete_account(int id);
	bool deposit(int id, int amount);
	bool withdraw(int id, int amount);
	bool loan(int id, int amount);
	
	friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
};

#endif // BANK_HPP