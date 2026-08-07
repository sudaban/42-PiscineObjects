#include "Workshop.hpp"
#include "Tool.hpp"

Workshop::Workshop(void)
	: m_name("Unnamed"), m_required_tool(""), m_workers()
{
	std::cout << "Workshop default constructor called" << std::endl;
}

Workshop::Workshop(const std::string &p_name)
	: m_name(p_name), m_required_tool(""), m_workers()
{
	std::cout << "Workshop parameterized constructor called (name="
		<< m_name << ")" << std::endl;
}

//bonus req
Workshop::Workshop(const std::string &p_name,
					const std::string &p_required_tool)
	: m_name(p_name), m_required_tool(p_required_tool), m_workers()
{
	std::cout << "Workshop parameterized constructor called (name="
		<< m_name << ", requires=" << m_required_tool << ")"
		<< std::endl;
}

Workshop::Workshop(const Workshop &p_other)
	: m_name(p_other.m_name),
	  m_required_tool(p_other.m_required_tool),
	  m_workers()
{
}

Workshop &Workshop::operator=(const Workshop &p_other)
{
	if (this != &p_other)
	{
		m_name = p_other.m_name;
		m_required_tool = p_other.m_required_tool;
		m_workers.clear();
	}
	return (*this);
}

Workshop::~Workshop(void)
{
	std::cout << "Workshop destructor called (name=" << m_name << ")"
		<< std::endl;
	for (std::size_t i = 0; i < m_workers.size(); ++i)
		m_workers[i]->LeaveWorkshop(this);
	m_workers.clear();
}

//bonus req
bool	Workshop::HasRequiredTool(const Worker *p_worker) const
{
	if (m_required_tool.empty())
		return (true);
	if (p_worker == NULL)
		return (false);
	const std::vector<Tool *> &tools = p_worker->GetTools();
	for (std::size_t i = 0; i < tools.size(); ++i)
	{
		if (tools[i] != NULL && tools[i]->GetTypeName() == m_required_tool)
			return (true);
	}
	return (false);
}

void	Workshop::RemoveWorkerInternal(Worker *p_worker)
{
	for (std::vector<Worker *>::iterator it = m_workers.begin();
		it != m_workers.end(); ++it)
	{
		if (*it == p_worker)
		{
			m_workers.erase(it);
			return;
		}
	}
}

void	Workshop::RegisterWorker(Worker *p_worker)
{
	if (p_worker == NULL)
		return;
	//bonus req
	if (!HasRequiredTool(p_worker))
	{
		std::cout << "Workshop " << m_name
			<< ": worker " << p_worker->GetName()
			<< " rejected (missing required tool "
			<< m_required_tool << ")" << std::endl;
		return;
	}
	m_workers.push_back(p_worker);
	p_worker->JoinWorkshop(this);
	std::cout << "Workshop " << m_name << ": worker "
		<< p_worker->GetName() << " registered" << std::endl;
}

void	Workshop::ReleaseWorker(Worker *p_worker)
{
	if (p_worker == NULL)
		return;
	for (std::vector<Worker *>::iterator it = m_workers.begin();
		it != m_workers.end(); ++it)
	{
		if (*it == p_worker)
		{
			m_workers.erase(it);
			p_worker->LeaveWorkshop(this);
			std::cout << "Workshop " << m_name
				<< ": worker " << p_worker->GetName()
				<< " released" << std::endl;
			return;
		}
	}
}

void	Workshop::ExecuteWorkDay(void)
{
	std::cout << "=== Workshop " << m_name
		<< " work day (workers=" << m_workers.size() << ") ==="
		<< std::endl;
	for (std::size_t i = 0; i < m_workers.size(); ++i)
		ExecuteWorkDayFor(m_workers[i]);
}

void	Workshop::ExecuteWorkDayFor(Worker *p_worker)
{
	if (p_worker == NULL)
		return;
	OnWorkerWork(p_worker);
}

void	Workshop::OnWorkerWork(Worker *p_worker)
{
	const std::vector<Tool *> &tools = p_worker->GetTools();
	if (tools.empty())
	{
		std::cout << "  " << p_worker->GetName()
			<< " has no tool to work with" << std::endl;
		return;
	}
	for (std::size_t i = 0; i < tools.size(); ++i)
	{
		if (tools[i] != NULL
			&& (m_required_tool.empty()
				|| tools[i]->GetTypeName() == m_required_tool))
		{
			std::cout << "  " << p_worker->GetName() << " works with "
				<< tools[i]->GetTypeName() << std::endl;
			tools[i]->Use();
			return;
		}
	}
	std::cout << "  " << p_worker->GetName()
		<< " has no matching tool for " << m_name << std::endl;
}

void	Workshop::SetRequiredTool(const std::string &p_tool_name)
{
	m_required_tool = p_tool_name;
}

const std::string	&Workshop::GetRequiredTool(void) const
{
	return (m_required_tool);
}

//bonus req
void	Workshop::NotifyToolChange(Worker *p_worker)
{
	if (p_worker == NULL)
		return;
	if (m_required_tool.empty())
		return;
	if (!HasRequiredTool(p_worker))
	{
		std::cout << "Workshop " << m_name
			<< ": worker " << p_worker->GetName()
			<< " auto-released (lost required tool "
			<< m_required_tool << ")" << std::endl;
		RemoveWorkerInternal(p_worker);
		p_worker->LeaveWorkshop(this);
	}
}

const std::string	&Workshop::GetName(void) const
{
	return (m_name);
}

std::size_t	Workshop::GetWorkerCount(void) const
{
	return (m_workers.size());
}

const std::vector<Worker *>	&Workshop::GetWorkers(void) const
{
	return (m_workers);
}

void	Workshop::Print(void) const
{
	std::cout << "Workshop(name=" << m_name
		<< ", required_tool=\"" << m_required_tool
		<< "\", workers=";
	for (std::size_t i = 0; i < m_workers.size(); ++i)
	{
		if (i > 0)
			std::cout << ",";
		std::cout << m_workers[i]->GetName();
	}
	std::cout << ")" << std::endl;
}