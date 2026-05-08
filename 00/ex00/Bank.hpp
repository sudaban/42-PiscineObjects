/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:44:33 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/08 13:53:42 by sdaban           ###   ########.fr       */
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
	std::vector<Account *> m_client_accounts;
	
public:
	Bank();
	
	int get_liquidity() const;
	std::vector<Account *> get_client_accounts() const;

	friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
};


#endif // BANK_HPP