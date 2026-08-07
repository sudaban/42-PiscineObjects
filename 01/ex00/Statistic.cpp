#include "Statistic.hpp"

Statistic::Statistic(void)
	: m_level(0), m_exp(0)
{
	std::cout << "Statistic default constructor called" << std::endl;
}

Statistic::Statistic(int p_level, int p_exp)
	: m_level(p_level), m_exp(p_exp)
{
	std::cout << "Statistic parameterized constructor called (level="
		<< m_level << ", exp=" << m_exp << ")" << std::endl;
}

Statistic::Statistic(const Statistic &p_other)
	: m_level(p_other.m_level), m_exp(p_other.m_exp)
{
}

Statistic &Statistic::operator=(const Statistic &p_other)
{
	if (this != &p_other)
	{
		m_level = p_other.m_level;
		m_exp = p_other.m_exp;
	}
	return (*this);
}

Statistic::~Statistic(void)
{
	std::cout << "Statistic destructor called" << std::endl;
}

void	Statistic::Print(void) const
{
	std::cout << "Statistic(level=" << m_level << ", exp=" << m_exp
		<< ")" << std::endl;
}
