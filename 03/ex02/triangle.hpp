#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <cmath>
# include "shape.hpp"

class Triangle : public Shape
{
public:
	Triangle(double side_a, double side_b, double side_c);

	virtual double GetArea() const;
	virtual double GetPerimeter() const;

	double GetSideA() const;
	double GetSideB() const;
	double GetSideC() const;

private:
	double m_side_a;
	double m_side_b;
	double m_side_c;
};

Triangle::Triangle(double side_a, double side_b, double side_c)
{
	if (side_a > 0 && side_b > 0 && side_c > 0
		&& side_a + side_b > side_c
		&& side_a + side_c > side_b
		&& side_b + side_c > side_a)
	{
		m_side_a = side_a;
		m_side_b = side_b;
		m_side_c = side_c;
	}
	else
	{
		m_side_a = 3;
		m_side_b = 4;
		m_side_c = 5;
	}
}

double Triangle::GetArea() const
{
	double half_perimeter = GetPerimeter() / 2;

	return std::sqrt(half_perimeter * (half_perimeter - m_side_a)
		* (half_perimeter - m_side_b) * (half_perimeter - m_side_c));
}

double Triangle::GetPerimeter() const
{
	return m_side_a + m_side_b + m_side_c;
}

double Triangle::GetSideA() const
{
	return m_side_a;
}

double Triangle::GetSideB() const
{
	return m_side_b;
}

double Triangle::GetSideC() const
{
	return m_side_c;
}

#endif
