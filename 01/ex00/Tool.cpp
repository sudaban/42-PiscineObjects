#include "Tool.hpp"

Tool::Tool(void)
	: m_number_of_uses(0), m_owner(NULL)
{
	std::cout << "Tool default constructor called" << std::endl;
}

Tool::Tool(const Tool &p_other)
	: m_number_of_uses(p_other.m_number_of_uses), m_owner(NULL)
{
	std::cout << "Tool copy constructor called" << std::endl;
}

Tool &Tool::operator=(const Tool &p_other)
{
	std::cout << "Tool assignment operator called" << std::endl;
	if (this != &p_other)
	{
		m_number_of_uses = p_other.m_number_of_uses;
	}
	return (*this);
}

Tool::~Tool(void)
{
	std::cout << "Tool destructor called" << std::endl;
}

int	Tool::GetNumberOfUses(void) const
{
	return (m_number_of_uses);
}

void	Tool::IncrementUses(void)
{
	++m_number_of_uses;
}

Worker	*Tool::GetOwner(void) const
{
	return (m_owner);
}

void	Tool::SetOwner(Worker *p_owner)
{
	m_owner = p_owner;
}
