#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <vector>
#include <string>
#include "Vector2.hpp"

class Graph
{
private:
	Vector2 m_size;
	std::vector<Vector2> m_points;
	std::vector<std::pair<Vector2, Vector2> > m_lines;

public:
	Graph();
	Graph(const Vector2& p_size);
	Graph(const Graph& p_other);
	Graph& operator=(const Graph& p_other);
	~Graph();

	Vector2 const& m_size_getter() const;
	int m_point_count_getter() const;
	int m_line_count_getter() const;

	void AddPoint(const Vector2& p_point);
	void AddLine(const Vector2& p_from, const Vector2& p_to);

	void Display() const;
	bool ExportPNG(const std::string& p_filename) const;
};

#endif
