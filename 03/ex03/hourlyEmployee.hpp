#ifndef HOURLYEMPLOYEE_HPP
# define HOURLYEMPLOYEE_HPP

# include "employee.hpp"

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(int hourly_value);

	virtual int executeWorkday();
	virtual int CalculateMonthlyPayroll();

	int GetWorkedHours() const;

protected:
	int m_worked_hours;
};

HourlyEmployee::HourlyEmployee(int hourly_value)
	: Employee(hourly_value), m_worked_hours(0) {}

int HourlyEmployee::executeWorkday()
{
	m_worked_hours += WORKDAY_HOURS;
	return WORKDAY_HOURS;
}

int HourlyEmployee::CalculateMonthlyPayroll()
{
	int payroll = m_worked_hours * hourlyValue;

	m_worked_hours = 0;
	return payroll;
}

int HourlyEmployee::GetWorkedHours() const
{
	return m_worked_hours;
}

class TempWorker : public HourlyEmployee
{
public:
	TempWorker(int hourly_value);

	void Mobilize(int hours);
};

TempWorker::TempWorker(int hourly_value) : HourlyEmployee(hourly_value) {}

void TempWorker::Mobilize(int hours)
{
	m_worked_hours += hours;
}

#endif
