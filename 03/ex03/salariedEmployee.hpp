#ifndef SALARIEDEMPLOYEE_HPP
# define SALARIEDEMPLOYEE_HPP

# include "employee.hpp"

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(int hourly_value, int monthly_salary);

	virtual int executeWorkday();
	virtual int CalculateMonthlyPayroll();

	int GetMonthlySalary() const;

protected:
	int m_monthly_salary;
};

SalariedEmployee::SalariedEmployee(int hourly_value, int monthly_salary)
	: Employee(hourly_value), m_monthly_salary(monthly_salary) {}

int SalariedEmployee::executeWorkday()
{
	return WORKDAY_HOURS;
}

int SalariedEmployee::CalculateMonthlyPayroll()
{
	return m_monthly_salary;
}

int SalariedEmployee::GetMonthlySalary() const
{
	return m_monthly_salary;
}

class ContractEmployee : public SalariedEmployee
{
public:
	ContractEmployee(int hourly_value, int monthly_salary);

	virtual int CalculateMonthlyPayroll();

	void RegisterNonWorkedHours(int hours);
	int GetNonWorkedHours() const;

protected:
	int m_non_worked_hours;
};

ContractEmployee::ContractEmployee(int hourly_value, int monthly_salary)
	: SalariedEmployee(hourly_value, monthly_salary), m_non_worked_hours(0) {}

int ContractEmployee::CalculateMonthlyPayroll()
{
	m_non_worked_hours = 0;
	return SalariedEmployee::CalculateMonthlyPayroll();
}

void ContractEmployee::RegisterNonWorkedHours(int hours)
{
	m_non_worked_hours += hours;
}

int ContractEmployee::GetNonWorkedHours() const
{
	return m_non_worked_hours;
}

class Apprentice : public ContractEmployee
{
public:
	Apprentice(int hourly_value, int monthly_salary);

	virtual int CalculateMonthlyPayroll();

	void RegisterSchoolHours(int hours);
	int GetSchoolHours() const;

private:
	int m_school_hours;
};

Apprentice::Apprentice(int hourly_value, int monthly_salary)
	: ContractEmployee(hourly_value, monthly_salary), m_school_hours(0) {}

int Apprentice::CalculateMonthlyPayroll()
{
	int payroll = ContractEmployee::CalculateMonthlyPayroll()
		+ m_school_hours * hourlyValue / 2;

	m_school_hours = 0;
	return payroll;
}

void Apprentice::RegisterSchoolHours(int hours)
{
	m_school_hours += hours;
}

int Apprentice::GetSchoolHours() const
{
	return m_school_hours;
}

#endif
