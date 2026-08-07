#include "Shovel.hpp"

const std::string	Shovel::TYPE_NAME = "Shovel";

Shovel::Shovel(void)
{
	std::cout << "Shovel default constructor called" << std::endl;
}

Shovel::Shovel(const Shovel &p_other) : Tool(p_other) {}

Shovel &Shovel::operator=(const Shovel &p_other)
{
	if (this != &p_other)
		Tool::operator=(p_other);
	return (*this);
}

Shovel::~Shovel(void)
{
	std::cout << "Shovel destructor called" << std::endl;
}

void	Shovel::Use(void)
{
	IncrementUses();
	std::cout << "Shovel used (total uses: " << m_number_of_uses << ")"
		<< std::endl;
}

const std::string	&Shovel::GetTypeName(void) const
{
	return (TYPE_NAME);
}
