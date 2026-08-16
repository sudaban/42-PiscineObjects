#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape
{
public:
	virtual ~Shape();

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
};

Shape::~Shape() {}

#endif
