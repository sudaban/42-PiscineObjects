#ifndef STATISTIC_HPP
# define STATISTIC_HPP

# include <iostream>

struct Statistic
{
	int		m_level;
	int		m_exp;

	Statistic(void);
	Statistic(int p_level, int p_exp);
	Statistic(const Statistic &p_other);
	Statistic &operator=(const Statistic &p_other);
	~Statistic(void);

	void	Print(void) const;
};

#endif
