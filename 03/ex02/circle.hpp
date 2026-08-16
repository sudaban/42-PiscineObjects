#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "shape.hpp"

static const double PI = 3.14159265358979323846;

class Circle : public Shape
{
public:
	Circle(double radius);

	virtual double GetArea() const;
	virtual double GetPerimeter() const;

	double GetRadius() const;

private:
	double m_radius;
};

Circle::Circle(double radius) : m_radius(radius) {}

double Circle::GetArea() const
{
	return PI * m_radius * m_radius;
}

double Circle::GetPerimeter() const
{
	return 2 * PI * m_radius;
}

double Circle::GetRadius() const
{
	return m_radius;
}

#endif
