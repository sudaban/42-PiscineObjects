#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <vector>
#include <string>
#include <utility>
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

		Vector2 const& GetSize() const;
		int GetPointCount() const;
		int GetLineCount() const;

		void AddPoint(const Vector2& p_point);
		void AddLine(const Vector2& p_from, const Vector2& p_to);

		void Display() const;
		bool ExportImage(const std::string& p_filename) const;

		static bool LoadFromFile(Graph& p_graph, const std::string& p_filename);
};

#endif
