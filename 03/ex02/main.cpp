#include <iostream>
#include <string>
#include <vector>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

void PrintShapeInfo(const Shape& shape)
{
	std::cout << "area:" << shape.GetArea()
		<< " perimeter:" << shape.GetPerimeter()
		<< std::endl;
}

int main()
{
	Rectangle rectangle(4, 5);
	Circle circle(3);
	Triangle triangle(3, 4, 5);

	PrintShapeInfo(rectangle);
	PrintShapeInfo(circle);
	PrintShapeInfo(triangle);

	std::vector<Shape*> shapes;
	shapes.push_back(&rectangle);
	shapes.push_back(&circle);
	shapes.push_back(&triangle);

	for (std::size_t i = 0; i < shapes.size(); ++i)
		PrintShapeInfo(*shapes[i]);
	return 0;
}
