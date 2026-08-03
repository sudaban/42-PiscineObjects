#include "Vector2.hpp"
#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

void header(const std::string& p_title)
{
	std::cout << std::endl << CYAN << "========================================" << std::endl;
	std::cout << " " << p_title << std::endl;
	std::cout << "========================================" << RESET << std::endl;
}

bool LoadFromFile(Graph& p_graph, const std::string& p_filename)
{
	std::ifstream var_file(p_filename.c_str());
	if (!var_file.is_open())
		return false;

	int var_w = 0, var_h = 0;
	var_file >> var_w >> var_h;
	if (var_w <= 0 || var_h <= 0)
		return false;

	int var_max_x = 0;
	int var_max_y = 0;

	std::string var_line;
	std::getline(var_file, var_line);

	while (std::getline(var_file, var_line))
	{
		if (var_line.empty())
			continue;
		if (var_line[0] == '#')
			continue;

		std::istringstream var_iss(var_line);
		std::string var_type;
		var_iss >> var_type;

		if (var_type == "P" || var_type == "p")
		{
			float var_x, var_y;
			var_iss >> var_x >> var_y;
			p_graph.AddPoint(Vector2(var_x, var_y));
			if (var_x > var_max_x) var_max_x = static_cast<int>(var_x);
			if (var_y > var_max_y) var_max_y = static_cast<int>(var_y);
		}
		else if (var_type == "L" || var_type == "l")
		{
			float var_x1, var_y1, var_x2, var_y2;
			var_iss >> var_x1 >> var_y1 >> var_x2 >> var_y2;
			p_graph.AddLine(Vector2(var_x1, var_y1), Vector2(var_x2, var_y2));
			if (var_x1 > var_max_x) var_max_x = static_cast<int>(var_x1);
			if (var_x2 > var_max_x) var_max_x = static_cast<int>(var_x2);
			if (var_y1 > var_max_y) var_max_y = static_cast<int>(var_y1);
			if (var_y2 > var_max_y) var_max_y = static_cast<int>(var_y2);
		}
	}

	var_file.close();
	(void)var_w;
	(void)var_h;
	return true;
}

int main()
{
	header("Test 1: Manual Points (Subject Example)");
	{
		Graph var_graph(Vector2(6, 6));
		var_graph.AddPoint(Vector2(0, 0));
		var_graph.AddPoint(Vector2(2, 2));
		var_graph.AddPoint(Vector2(4, 2));
		var_graph.AddPoint(Vector2(2, 4));
		var_graph.Display();
	}

	header("Test 2: With Lines");
	{
		Graph var_graph(Vector2(10, 10));
		var_graph.AddPoint(Vector2(0, 0));
		var_graph.AddPoint(Vector2(9, 9));
		var_graph.AddPoint(Vector2(5, 2));
		var_graph.AddLine(Vector2(0, 0), Vector2(9, 9));
		var_graph.AddLine(Vector2(0, 9), Vector2(9, 0));
		var_graph.Display();
	}

	header("Test 3: Encapsulation Test");
	{
		Graph var_graph(Vector2(5, 5));
		std::cout << "Point count: " << var_graph.m_point_count_getter() << std::endl;
		std::cout << "Size: (" << var_graph.m_size_getter().m_x_getter()
				  << ", " << var_graph.m_size_getter().m_y_getter() << ")" << std::endl;
		var_graph.AddPoint(Vector2(1, 1));
		var_graph.AddPoint(Vector2(3, 3));
		std::cout << "Point count after adding 2: " << var_graph.m_point_count_getter() << std::endl;
		var_graph.Display();
	}

	header("Test 4: Read from file (input.txt)");
	{
		Graph var_graph(Vector2(15, 15));
		if (LoadFromFile(var_graph, "input.txt"))
		{
			std::cout << "Loaded " << var_graph.m_point_count_getter() << " points and "
					  << var_graph.m_line_count_getter() << " lines from input.txt" << std::endl;
			var_graph.Display();
		}
		else
		{
			std::cout << YELLOW << "[INFO] input.txt not found, skipping..." << RESET << std::endl;
		}
	}

	header("Test 5: PNG Export");
	{
		Graph var_graph(Vector2(8, 8));
		var_graph.AddPoint(Vector2(1, 1));
		var_graph.AddPoint(Vector2(6, 6));
		var_graph.AddPoint(Vector2(2, 5));
		var_graph.AddLine(Vector2(1, 1), Vector2(6, 6));
		var_graph.AddLine(Vector2(1, 6), Vector2(6, 1));
		if (var_graph.ExportPNG("graph_output.ppm"))
			std::cout << GREEN << "[OK] " << RESET << "Image saved to graph_output.ppm" << std::endl;
		else
			std::cout << RED << "[ERR] " << RESET << "Failed to save image" << std::endl;
	}

	std::cout << std::endl << GREEN << "=== All tests completed ===" << RESET << std::endl;
	return 0;
}
