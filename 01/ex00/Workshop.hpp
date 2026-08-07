#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <vector>
# include <string>
# include "Worker.hpp"

class Workshop
{
public:
	Workshop(void);
	Workshop(const std::string &p_name);
	Workshop(const Workshop &p_other);
	Workshop &operator=(const Workshop &p_other);
	virtual	~Workshop(void);

	void			RegisterWorker(Worker *p_worker);
	void			ReleaseWorker(Worker *p_worker);
	void			ExecuteWorkDay(void);

	//bonus req
	Workshop(const std::string &p_name, const std::string &p_required_tool);
	void			SetRequiredTool(const std::string &p_tool_name);
	const std::string	&GetRequiredTool(void) const;

	//bonus req
	void			NotifyToolChange(Worker *p_worker);

	void			ExecuteWorkDayFor(Worker *p_worker);

	const std::string		&GetName(void) const;
	std::size_t				GetWorkerCount(void) const;
	const std::vector<Worker *>	&GetWorkers(void) const;
	void					Print(void) const;

protected:
	virtual void	OnWorkerWork(Worker *p_worker);

private:
	bool	HasRequiredTool(const Worker *p_worker) const;
	void	RemoveWorkerInternal(Worker *p_worker);

	std::string				m_name;
	std::string				m_required_tool;
	std::vector<Worker *>	m_workers;
};

#endif
