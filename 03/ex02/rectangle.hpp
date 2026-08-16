#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(double width, double height);

	virtual double GetArea() const;
	virtual double GetPerimeter() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	double m_width;
	double m_height;
};

Rectangle::Rectangle(double width, double height) : m_width(width), m_height(height) {}

double Rectangle::GetArea() const
{
	return m_width * m_height;
}

double Rectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

double Rectangle::GetWidth() const
{
	return m_width;
}

double Rectangle::GetHeight() const
{
	return m_height;
}

#endif
