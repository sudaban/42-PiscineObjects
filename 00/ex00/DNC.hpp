/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DNC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:27:17 by sdaban            #+#    #+#             */
/*   Updated: 2026/05/08 13:43:21 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DNC_HPP
# define DNC_HPP

#include <string>
#include <iostream>

class DNC
{
private:
	std::string m_name;

	public:
	DNC();
	~DNC();
};

#endif // DNC_HPP