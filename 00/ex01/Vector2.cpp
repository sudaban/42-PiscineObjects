#include "Vector2.hpp"

Vector2::Vector2() : m_x(0), m_y(0) {}

Vector2::Vector2(float p_x, float p_y) : m_x(p_x), m_y(p_y) {}

Vector2::Vector2(const Vector2& p_other) : m_x(p_other.m_x), m_y(p_other.m_y) {}

Vector2& Vector2::operator=(const Vector2& p_other)
{
	if (this != &p_other)
	{
		this->m_x = p_other.m_x;
		this->m_y = p_other.m_y;
	}
	return *this;
}

Vector2::~Vector2() {}

float Vector2::m_x_getter() const
{
	return this->m_x;
}

float Vector2::m_y_getter() const
{
	return this->m_y;
}

void Vector2::m_x_setter(float p_x)
{
	this->m_x = p_x;
}

void Vector2::m_y_setter(float p_y)
{
	this->m_y = p_y;
}

bool Vector2::operator==(const Vector2& p_other) const
{
	return (this->m_x == p_other.m_x && this->m_y == p_other.m_y);
}

bool Vector2::operator!=(const Vector2& p_other) const
{
	return !(*this == p_other);
}
