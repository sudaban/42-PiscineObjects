#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class Employee
{
public:
	enum
	{
		WORKDAY_HOURS = 7
	};

	Employee(int hourly_value);
	virtual ~Employee();

	virtual int executeWorkday() = 0;
	virtual int CalculateMonthlyPayroll() = 0;

protected:
	int hourlyValue;
};

Employee::Employee(int hourly_value) : hourlyValue(hourly_value) {}

Employee::~Employee() {}

#endif
