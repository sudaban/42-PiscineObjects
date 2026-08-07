#include "Worker.hpp"
#include "Workshop.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Worker::Worker(void)
	: m_name("Anonymous"), m_coordonnee(), m_stat(),
	  m_tools(), m_workshops()
{
	std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(const std::string &p_name)
	: m_name(p_name), m_coordonnee(), m_stat(),
	  m_tools(), m_workshops()
{
	std::cout << "Worker parameterized constructor called (name="
		<< m_name << ")" << std::endl;
}

Worker::Worker(const Worker &p_other)
	: m_name(p_other.m_name),
	  m_coordonnee(p_other.m_coordonnee),
	  m_stat(p_other.m_stat),
	  m_tools(), m_workshops()
{
	std::cout << "Worker copy constructor called (name=" << m_name << ")"
		<< std::endl;
}

Worker &Worker::operator=(const Worker &p_other)
{
	std::cout << "Worker assignment operator called" << std::endl;
	if (this != &p_other)
	{
		m_name = p_other.m_name;
		m_coordonnee = p_other.m_coordonnee;
		m_stat = p_other.m_stat;
	}
	return (*this);
}

Worker::~Worker(void)
{
	std::cout << "Worker destructor called (name=" << m_name << ")"
		<< std::endl;
	LeaveAllWorkshops();
	m_tools.clear();
}

const Position	&Worker::GetCoordonnee(void) const
{
	return (m_coordonnee);
}

Position		&Worker::GetCoordonnee(void)
{
	return (m_coordonnee);
}

void			Worker::SetCoordonnee(const Position &p_pos)
{
	m_coordonnee = p_pos;
}

const Statistic	&Worker::GetStat(void) const
{
	return (m_stat);
}

Statistic		&Worker::GetStat(void)
{
	return (m_stat);
}

void			Worker::SetStat(const Statistic &p_stat)
{
	m_stat = p_stat;
}

void			Worker::GiveTool(Tool *p_tool)
{
	if (p_tool == NULL)
	{
		std::cout << "Worker " << m_name
			<< ": cannot give a NULL tool" << std::endl;
		return;
	}

	if (p_tool->GetOwner() != NULL && p_tool->GetOwner() != this)
		p_tool->GetOwner()->TakeTool(p_tool);

	p_tool->SetOwner(this);
	m_tools.push_back(p_tool);
	std::cout << "Worker " << m_name << " received a "
		<< p_tool->GetTypeName() << std::endl;
}

Tool			*Worker::TakeTool(Tool *p_tool)
{
	if (p_tool == NULL)
		return (NULL);

	for (std::vector<Tool *>::iterator it = m_tools.begin();
		it != m_tools.end(); ++it)
	{
		if (*it == p_tool)
		{
			m_tools.erase(it);
			p_tool->SetOwner(NULL);
			std::cout << "Worker " << m_name << " released a "
				<< p_tool->GetTypeName() << std::endl;
			//bonus req
			for (std::size_t i = 0; i < m_workshops.size(); ++i)
				m_workshops[i]->NotifyToolChange(this);
			return (p_tool);
		}
	}
	return (NULL);
}

void			Worker::ReleaseAllTools(void)
{
	while (!m_tools.empty())
		TakeTool(m_tools.back());
}

const std::vector<Tool *>	&Worker::GetTools(void) const
{
	return (m_tools);
}

std::size_t		Worker::GetToolCount(void) const
{
	return (m_tools.size());
}

void			Worker::JoinWorkshop(Workshop *p_workshop)
{
	if (p_workshop == NULL)
		return;
	for (std::size_t i = 0; i < m_workshops.size(); ++i)
	{
		if (m_workshops[i] == p_workshop)
		{
			std::cout << "Worker " << m_name
				<< " already in this workshop" << std::endl;
			return;
		}
	}
	m_workshops.push_back(p_workshop);
	std::cout << "Worker " << m_name << " joined a workshop" << std::endl;
}

void			Worker::LeaveWorkshop(Workshop *p_workshop)
{
	for (std::vector<Workshop *>::iterator it = m_workshops.begin();
		it != m_workshops.end(); ++it)
	{
		if (*it == p_workshop)
		{
			m_workshops.erase(it);
			std::cout << "Worker " << m_name
				<< " left a workshop" << std::endl;
			return;
		}
	}
}

const std::vector<Workshop *>	&Worker::GetWorkshops(void) const
{
	return (m_workshops);
}

void			Worker::LeaveAllWorkshops(void)
{
	while (!m_workshops.empty())
	{
		Workshop *w = m_workshops.back();
		m_workshops.pop_back();
		if (w != NULL)
			w->ReleaseWorker(this);
	}
}

void			Worker::Work(void)
{
	if (m_workshops.empty())
	{
		std::cout << "Worker " << m_name
			<< " is not registered to any workshop, cannot work"
			<< std::endl;
		return;
	}
	for (std::size_t i = 0; i < m_workshops.size(); ++i)
		m_workshops[i]->ExecuteWorkDayFor(this);
}

const std::string	&Worker::GetName(void) const
{
	return (m_name);
}

void			Worker::Print(void) const
{
	std::cout << "Worker(name=" << m_name << ", coordonnee=("
		<< m_coordonnee.m_x << "," << m_coordonnee.m_y << ","
		<< m_coordonnee.m_z << "), level=" << m_stat.m_level
		<< ", exp=" << m_stat.m_exp << ", tools=";
	for (std::size_t i = 0; i < m_tools.size(); ++i)
	{
		if (i > 0)
			std::cout << ",";
		std::cout << m_tools[i]->GetTypeName();
	}
	std::cout << ")" << std::endl;
}
