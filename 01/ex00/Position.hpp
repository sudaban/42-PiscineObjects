#ifndef POSITION_HPP
# define POSITION_HPP

# include <iostream>

struct Position
{
	int		m_x;
	int		m_y;
	int		m_z;

	Position(void);
	Position(int p_x, int p_y, int p_z);
	Position(const Position &p_other);
	Position &operator=(const Position &p_other);
	~Position(void);

	void	Print(void) const;
};

#endif
