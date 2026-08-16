#ifndef EMPLOYEEMANAGEMENT_HPP
# define EMPLOYEEMANAGEMENT_HPP

# include <iostream>
# include <vector>
# include "employee.hpp"

class EmployeeManager
{
public:
	void addEmployee(Employee* employee);
	void removeEmployee(Employee* employee);
	void executeWorkday();
	void calculatePayroll();

private:
	std::vector<Employee*> m_employees;
};

void EmployeeManager::addEmployee(Employee* employee)
{
	if (employee != 0)
		m_employees.push_back(employee);
}

void EmployeeManager::removeEmployee(Employee* employee)
{
	for (std::vector<Employee*>::iterator it = m_employees.begin();
		it != m_employees.end();)
	{
		if (*it == employee)
			it = m_employees.erase(it);
		else
			++it;
	}
}

void EmployeeManager::executeWorkday()
{
	for (std::size_t i = 0; i < m_employees.size(); ++i)
		m_employees[i]->executeWorkday();
}

void EmployeeManager::calculatePayroll()
{
	for (std::size_t i = 0; i < m_employees.size(); ++i)
		std::cout << "employee " << (i + 1) << ": "
			<< m_employees[i]->CalculateMonthlyPayroll() << " euros"
			<< std::endl;
}

#endif
