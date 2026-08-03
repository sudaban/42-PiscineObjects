#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <cstdlib>

Graph::Graph() : m_size(0, 0), m_points(), m_lines() {}

Graph::Graph(const Vector2& p_size) : m_size(p_size), m_points(), m_lines() {}

Graph::Graph(const Graph& p_other)
	: m_size(p_other.m_size), m_points(p_other.m_points), m_lines(p_other.m_lines) {}

Graph& Graph::operator=(const Graph& p_other)
{
	if (this != &p_other)
	{
		this->m_size = p_other.m_size;
		this->m_points = p_other.m_points;
		this->m_lines = p_other.m_lines;
	}
	return *this;
}

Graph::~Graph() {}

Vector2 const& Graph::GetSize() const
{
	return this->m_size;
}

int Graph::GetPointCount() const
{
	return static_cast<int>(this->m_points.size());
}

int Graph::GetLineCount() const
{
	return static_cast<int>(this->m_lines.size());
}

void Graph::AddPoint(const Vector2& p_point)
{
	this->m_points.push_back(p_point);
}

void Graph::AddLine(const Vector2& p_from, const Vector2& p_to)
{
	this->m_lines.push_back(std::make_pair(p_from, p_to));
}

static int RoundFloat(float p_value)
{
	return static_cast<int>(std::floor(p_value + 0.5f));
}

static int ClampInt(int p_value, int p_min, int p_max)
{
	if (p_value < p_min)
		return p_min;
	if (p_value > p_max)
		return p_max;
	return p_value;
}

void Graph::Display() const
{
	int var_width = RoundFloat(this->m_size.GetX());
	int var_height = RoundFloat(this->m_size.GetY());

	if (var_width <= 0 || var_height <= 0)
	{
		std::cout << "[Graph] Empty graph" << std::endl;
		return;
	}

	int var_w = var_width;
	int var_h = var_height;

	char** var_grid = new char*[var_h];
	for (int var_i = 0; var_i < var_h; ++var_i)
	{
		var_grid[var_i] = new char[var_w];
		for (int var_j = 0; var_j < var_w; ++var_j)
			var_grid[var_i][var_j] = '.';
	}

	for (std::vector<std::pair<Vector2, Vector2> >::const_iterator var_lit = this->m_lines.begin(); var_lit != this->m_lines.end(); ++var_lit)
	{
		float var_x0 = var_lit->first.GetX();
		float var_y0 = var_lit->first.GetY();
		float var_x1 = var_lit->second.GetX();
		float var_y1 = var_lit->second.GetY();

		int var_steps = std::max(abs(RoundFloat(var_x1) - RoundFloat(var_x0)),
			abs(RoundFloat(var_y1) - RoundFloat(var_y0)));
		if (var_steps == 0)
			var_steps = 1;

		for (int var_s = 0; var_s <= var_steps; ++var_s)
		{
			float var_t = static_cast<float>(var_s) / static_cast<float>(var_steps);
			float var_cx = var_x0 + (var_x1 - var_x0) * var_t;
			float var_cy = var_y0 + (var_y1 - var_y0) * var_t;
			int var_xi = RoundFloat(var_cx);
			int var_yi = RoundFloat(var_cy);
			if (var_xi >= 0 && var_xi < var_w && var_yi >= 0 && var_yi < var_h)
				var_grid[var_yi][var_xi] = '*';
		}
	}

	for (std::vector<Vector2>::const_iterator var_it = this->m_points.begin(); var_it != this->m_points.end(); ++var_it)
	{
		int var_xi = RoundFloat(var_it->GetX());
		int var_yi = RoundFloat(var_it->GetY());
		if (var_xi >= 0 && var_xi < var_w && var_yi >= 0 && var_yi < var_h)
			var_grid[var_yi][var_xi] = 'X';
	}

	for (int var_i = var_h - 1; var_i >= 0; --var_i)
	{
		std::cout << ">& " << var_i;
		for (int var_j = 0; var_j < var_w; ++var_j)
			std::cout << " " << var_grid[var_i][var_j];
		std::cout << std::endl;
	}

	std::cout << ">& ";
	for (int var_j = 0; var_j < var_w; ++var_j)
		std::cout << " " << var_j;
	std::cout << std::endl;

	for (int var_i = 0; var_i < var_h; ++var_i)
		delete[] var_grid[var_i];
	delete[] var_grid;
}

bool Graph::ExportImage(const std::string& p_filename) const
{
	int var_w = ClampInt(RoundFloat(this->m_size.GetX()) * 20, 100, 2000);
	int var_h = ClampInt(RoundFloat(this->m_size.GetY()) * 20, 100, 2000);

	int var_gw = RoundFloat(this->m_size.GetX());
	int var_gh = RoundFloat(this->m_size.GetY());

	std::ofstream var_file(p_filename.c_str(), std::ios::binary);
	if (!var_file.is_open())
		return false;

	var_file << "P3\n" << var_w << " " << var_h << "\n255\n";

	for (int var_y = var_h - 1; var_y >= 0; --var_y)
	{
		for (int var_x = 0; var_x < var_w; ++var_x)
		{
			int var_r = 20;
			int var_g = 20;
			int var_b = 30;

			bool var_on_line = false;
			for (std::vector<std::pair<Vector2, Vector2> >::const_iterator var_lit = this->m_lines.begin(); var_lit != this->m_lines.end(); ++var_lit)
			{
				float var_fx0 = var_lit->first.GetX();
				float var_fy0 = var_lit->first.GetY();
				float var_fx1 = var_lit->second.GetX();
				float var_fy1 = var_lit->second.GetY();

				float var_lx0 = (var_fx0 / (var_gw > 0 ? var_gw : 1)) * var_w;
				float var_ly0 = (var_fy0 / (var_gh > 0 ? var_gh : 1)) * var_h;
				float var_lx1 = (var_fx1 / (var_gw > 0 ? var_gw : 1)) * var_w;
				float var_ly1 = (var_fy1 / (var_gh > 0 ? var_gh : 1)) * var_h;

				float var_dx = var_lx1 - var_lx0;
				float var_dy = var_ly1 - var_ly0;
				float var_len2 = var_dx * var_dx + var_dy * var_dy;
				if (var_len2 < 0.001f) continue;
				float var_t = ((var_x - var_lx0) * var_dx + (var_h - 1 - var_y - var_ly0) * var_dy) / var_len2;
				if (var_t < 0.0f) var_t = 0.0f;
				if (var_t > 1.0f) var_t = 1.0f;
				float var_px = var_lx0 + var_t * var_dx;
				float var_py = var_ly0 + var_t * var_dy;
				float var_dist = std::sqrt((var_x - var_px) * (var_x - var_px) + ((var_h - 1 - var_y) - var_py) * ((var_h - 1 - var_y) - var_py));
				if (var_dist < 2.0f)
				{
					var_on_line = true;
					break;
				}
			}

			if (var_on_line)
			{
				var_r = 100; var_g = 200; var_b = 255;
			}

			for (std::vector<Vector2>::const_iterator var_it = this->m_points.begin(); var_it != this->m_points.end(); ++var_it)
			{
				float var_px = (var_it->GetX() / (var_gw > 0 ? var_gw : 1)) * var_w;
				float var_py = (var_it->GetY() / (var_gh > 0 ? var_gh : 1)) * var_h;
				float var_dx = var_x - var_px;
				float var_dy = (var_h - 1 - var_y) - var_py;
				float var_dist = std::sqrt(var_dx * var_dx + var_dy * var_dy);
				if (var_dist < 6.0f)
				{
					var_r = 255; var_g = 80; var_b = 80;
				}
			}

			var_file << var_r << " " << var_g << " " << var_b << "\n";
		}
	}

	var_file.close();
	return true;
}

bool Graph::LoadFromFile(Graph& p_graph, const std::string& p_filename)
{
	std::ifstream var_file(p_filename.c_str());
	if (!var_file.is_open())
		return false;

	int var_w = 0, var_h = 0;
	var_file >> var_w >> var_h;
	if (var_w <= 0 || var_h <= 0)
		return false;

	p_graph.m_size = Vector2(static_cast<float>(var_w), static_cast<float>(var_h));

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
		}
		else if (var_type == "L" || var_type == "l")
		{
			float var_x1, var_y1, var_x2, var_y2;
			var_iss >> var_x1 >> var_y1 >> var_x2 >> var_y2;
			p_graph.AddLine(Vector2(var_x1, var_y1), Vector2(var_x2, var_y2));
		}
	}

	var_file.close();
	return true;
}
