#include "Hammer.hpp"

const std::string	Hammer::TYPE_NAME = "Hammer";

Hammer::Hammer(void)
{
	std::cout << "Hammer default constructor called" << std::endl;
}

Hammer::Hammer(const Hammer &p_other)
	: Tool(p_other)
{
	std::cout << "Hammer copy constructor called" << std::endl;
}

Hammer &Hammer::operator=(const Hammer &p_other)
{
	std::cout << "Hammer assignment operator called" << std::endl;
	if (this != &p_other)
		Tool::operator=(p_other);
	return (*this);
}

Hammer::~Hammer(void)
{
	std::cout << "Hammer destructor called" << std::endl;
}

void	Hammer::Use(void)
{
	IncrementUses();
	std::cout << "Hammer used (total uses: " << m_number_of_uses << ")"
		<< std::endl;
}

const std::string	&Hammer::GetTypeName(void) const
{
	return (TYPE_NAME);
}
