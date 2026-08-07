#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <vector>
# include <string>
# include "Position.hpp"
# include "Statistic.hpp"
# include "Tool.hpp"

class Workshop;

class Worker
{
public:
	Worker(void);
	Worker(const std::string &p_name);
	Worker(const Worker &p_other);
	Worker &operator=(const Worker &p_other);
	~Worker(void);

	const Position		&GetCoordonnee(void) const;
	Position			&GetCoordonnee(void);
	void				SetCoordonnee(const Position &p_pos);
	const Statistic		&GetStat(void) const;
	Statistic			&GetStat(void);
	void				SetStat(const Statistic &p_stat);

	void				GiveTool(Tool *p_tool);
	Tool				*TakeTool(Tool *p_tool);
	void				ReleaseAllTools(void);
	const std::vector<Tool *>	&GetTools(void) const;
	std::size_t			GetToolCount(void) const;

	//bonus req
	template <typename ToolType>
	ToolType			*GetTool(void)
	{
		for (std::size_t i = 0; i < m_tools.size(); ++i)
		{
			ToolType *casted = dynamic_cast<ToolType *>(m_tools[i]);
			if (casted != NULL)
				return (casted);
		}
		return (NULL);
	}

	void				JoinWorkshop(Workshop *p_workshop);
	void				LeaveWorkshop(Workshop *p_workshop);
	const std::vector<Workshop *>	&GetWorkshops(void) const;
	void				LeaveAllWorkshops(void);

	void				Work(void);

	const std::string	&GetName(void) const;
	void				Print(void) const;

private:
	std::string				m_name;
	Position				m_coordonnee;
	Statistic				m_stat;
	std::vector<Tool *>		m_tools;
	std::vector<Workshop *>	m_workshops;
};

#endif