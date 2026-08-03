#include "Vector2.hpp"
#include "Graph.hpp"
#include <iostream>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

void Header(const std::string& p_title)
{
	std::cout << std::endl << CYAN << "========================================" << std::endl;
	std::cout << " " << p_title << std::endl;
	std::cout << "========================================" << RESET << std::endl;
}

void Ok(const std::string& p_msg)
{
	std::cout << GREEN << "[OK] " << RESET << p_msg << std::endl;
}

void Info(const std::string& p_msg)
{
	std::cout << BLUE << "[INFO] " << RESET << p_msg << std::endl;
}

int main()
{
	Header("BONUS ex01: Line + Image Export + File Reading");

	Header("Test 1: Subject example (6x6, 4 points)");
	{
		Graph var_graph(Vector2(6, 6));
		var_graph.AddPoint(Vector2(0, 0));
		var_graph.AddPoint(Vector2(2, 2));
		var_graph.AddPoint(Vector2(4, 2));
		var_graph.AddPoint(Vector2(2, 4));
		var_graph.Display();
	}

	Header("Test 2: Bonus - Add lines to graph");
	{
		Graph var_graph(Vector2(10, 10));
		var_graph.AddPoint(Vector2(0, 0));
		var_graph.AddPoint(Vector2(9, 9));
		var_graph.AddPoint(Vector2(5, 5));
		var_graph.AddLine(Vector2(0, 0), Vector2(9, 9));
		var_graph.AddLine(Vector2(0, 9), Vector2(9, 0));
		Info("2 points + 3 points + 2 lines:");
		var_graph.Display();
	}

	Header("Test 3: Bonus - Read from input.txt");
	{
		Graph var_graph(Vector2(10, 10));
		if (Graph::LoadFromFile(var_graph, "input.txt"))
		{
			Ok("Loaded graph from input.txt");
			std::cout << BLUE << "[INFO] " << RESET << "Point count: " << var_graph.GetPointCount() << std::endl;
			std::cout << BLUE << "[INFO] " << RESET << "Line count: " << var_graph.GetLineCount() << std::endl;
			var_graph.Display();
		}
		else
		{
			std::cout << YELLOW << "[INFO] input.txt not found" << RESET << std::endl;
		}
	}

	Header("Test 4: Bonus - Export image (PPM format)");
	{
		Graph var_graph(Vector2(10, 10));
		var_graph.AddPoint(Vector2(1, 1));
		var_graph.AddPoint(Vector2(8, 8));
		var_graph.AddPoint(Vector2(2, 7));
		var_graph.AddPoint(Vector2(7, 2));
		var_graph.AddLine(Vector2(1, 1), Vector2(8, 8));
		var_graph.AddLine(Vector2(2, 7), Vector2(7, 2));
		var_graph.AddLine(Vector2(0, 5), Vector2(9, 5));
		if (var_graph.ExportImage("bonus_graph.ppm"))
			Ok("Image saved to bonus_graph.ppm (P3 PPM format)");
		else
			std::cout << RED << "[ERR] Failed to save image" << RESET << std::endl;
	}

	Header("Test 5: Encapsulation - getter access only");
	{
		Graph var_graph(Vector2(5, 5));
		std::cout << "Size via getter: (" << var_graph.GetSize().GetX() << ", " << var_graph.GetSize().GetY() << ")" << std::endl;
		std::cout << "Point count via getter: " << var_graph.GetPointCount() << std::endl;
		var_graph.AddPoint(Vector2(1, 1));
		var_graph.AddPoint(Vector2(3, 3));
		var_graph.AddLine(Vector2(1, 1), Vector2(3, 3));
		std::cout << "After adding: points=" << var_graph.GetPointCount() << " lines=" << var_graph.GetLineCount() << std::endl;
		var_graph.Display();
	}

	Header("Bonus Compliance Summary");
	Info("1. Line feature: AddLine() with Bresenham-style interpolation");
	Info("2. Image export: ExportImage() outputs P3 PPM (no external libs)");
	Info("3. File reading: LoadFromFile() parses P (point) and L (line) entries");

	std::cout << std::endl << GREEN << "=== Bonus ex01 tests completed ===" << RESET << std::endl;
	return 0;
}
