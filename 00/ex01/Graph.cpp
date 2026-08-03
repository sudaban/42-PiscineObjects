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

Vector2 const& Graph::m_size_getter() const
{
	return this->m_size;
}

int Graph::m_point_count_getter() const
{
	return static_cast<int>(this->m_points.size());
}

int Graph::m_line_count_getter() const
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

static int FunctionRoundFloat(float p_value)
{
	return static_cast<int>(std::floor(p_value + 0.5f));
}

static int FunctionClampInt(int p_value, int p_min, int p_max)
{
	if (p_value < p_min)
		return p_min;
	if (p_value > p_max)
		return p_max;
	return p_value;
}

void Graph::Display() const
{
	int var_width = FunctionRoundFloat(this->m_size.m_x_getter());
	int var_height = FunctionRoundFloat(this->m_size.m_y_getter());

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
		float var_x0 = var_lit->first.m_x_getter();
		float var_y0 = var_lit->first.m_y_getter();
		float var_x1 = var_lit->second.m_x_getter();
		float var_y1 = var_lit->second.m_y_getter();

		int var_steps = std::max(abs(FunctionRoundFloat(var_x1) - FunctionRoundFloat(var_x0)),
			abs(FunctionRoundFloat(var_y1) - FunctionRoundFloat(var_y0)));
		if (var_steps == 0)
			var_steps = 1;

		for (int var_s = 0; var_s <= var_steps; ++var_s)
		{
			float var_t = static_cast<float>(var_s) / static_cast<float>(var_steps);
			float var_cx = var_x0 + (var_x1 - var_x0) * var_t;
			float var_cy = var_y0 + (var_y1 - var_y0) * var_t;
			int var_xi = FunctionRoundFloat(var_cx);
			int var_yi = FunctionRoundFloat(var_cy);
			if (var_xi >= 0 && var_xi < var_w && var_yi >= 0 && var_yi < var_h)
				var_grid[var_yi][var_xi] = '*';
		}
	}

	for (std::vector<Vector2>::const_iterator var_it = this->m_points.begin(); var_it != this->m_points.end(); ++var_it)
	{
		int var_xi = FunctionRoundFloat(var_it->m_x_getter());
		int var_yi = FunctionRoundFloat(var_it->m_y_getter());
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

bool Graph::ExportPNG(const std::string& p_filename) const
{
	int var_w = FunctionClampInt(FunctionRoundFloat(this->m_size.m_x_getter()) * 20, 100, 2000);
	int var_h = FunctionClampInt(FunctionRoundFloat(this->m_size.m_y_getter()) * 20, 100, 2000);

	int var_gw = FunctionRoundFloat(this->m_size.m_x_getter());
	int var_gh = FunctionRoundFloat(this->m_size.m_y_getter());

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

			int var_cell_x = (var_x * var_gw) / var_w;
			int var_cell_y = (var_y * var_gh) / var_h;
			if (var_cell_x < 0) var_cell_x = 0;
			if (var_cell_x >= var_gw) var_cell_x = var_gw - 1;
			if (var_cell_y < 0) var_cell_y = 0;
			if (var_cell_y >= var_gh) var_cell_y = var_gh - 1;

			bool var_on_line = false;
			for (std::vector<std::pair<Vector2, Vector2> >::const_iterator var_lit = this->m_lines.begin(); var_lit != this->m_lines.end(); ++var_lit)
			{
				float var_fx0 = var_lit->first.m_x_getter();
				float var_fy0 = var_lit->first.m_y_getter();
				float var_fx1 = var_lit->second.m_x_getter();
				float var_fy1 = var_lit->second.m_y_getter();

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
				float var_px = (var_it->m_x_getter() / (var_gw > 0 ? var_gw : 1)) * var_w;
				float var_py = (var_it->m_y_getter() / (var_gh > 0 ? var_gh : 1)) * var_h;
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
