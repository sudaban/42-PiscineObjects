#include "Position.hpp"

Position::Position(void)
	: m_x(0), m_y(0), m_z(0)
{
	std::cout << "Position default constructor called" << std::endl;
}

Position::Position(int p_x, int p_y, int p_z)
	: m_x(p_x), m_y(p_y), m_z(p_z)
{
	std::cout << "Position parameterized constructor called (x=" << m_x
		<< ", y=" << m_y << ", z=" << m_z << ")" << std::endl;
}

Position::Position(const Position &p_other)
	: m_x(p_other.m_x), m_y(p_other.m_y), m_z(p_other.m_z)
{
	std::cout << "Position copy constructor called" << std::endl;
}

Position &Position::operator=(const Position &p_other)
{
	std::cout << "Position assignment operator called" << std::endl;
	if (this != &p_other)
	{
		m_x = p_other.m_x;
		m_y = p_other.m_y;
		m_z = p_other.m_z;
	}
	return (*this);
}

Position::~Position(void)
{
	std::cout << "Position destructor called" << std::endl;
}

void	Position::Print(void) const
{
	std::cout << "Position(x=" << m_x << ", y=" << m_y
		<< ", z=" << m_z << ")" << std::endl;
}
