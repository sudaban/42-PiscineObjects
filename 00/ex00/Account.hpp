/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:45:41 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/08 13:52:40 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

#include <iostream>
#include <vector>

class Account
{
	int m_id;
	int m_value;

public:
	Account();

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

#endif // ACCOUNT_HPP