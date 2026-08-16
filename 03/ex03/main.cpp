#include <iostream>
#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main()
{
	TempWorker temp_worker(20);
	ContractEmployee contract_employee(25, 3000);
	Apprentice apprentice(15, 2000);
	TempWorker extra_worker(18);

	EmployeeManager manager;
	manager.addEmployee(&temp_worker);
	manager.addEmployee(&contract_employee);
	manager.addEmployee(&apprentice);
	manager.addEmployee(&extra_worker);

	temp_worker.Mobilize(8);
	contract_employee.RegisterNonWorkedHours(7);
	apprentice.RegisterSchoolHours(14);
	extra_worker.Mobilize(4);

	std::cout << "temp worker hours:" << temp_worker.GetWorkedHours() << std::endl;
	std::cout << "contract employee non worked hours:"
		<< contract_employee.GetNonWorkedHours() << std::endl;
	std::cout << "apprentice school hours:" << apprentice.GetSchoolHours() << std::endl;

	manager.removeEmployee(&extra_worker);

	for (int day = 0; day < 20; ++day)
		manager.executeWorkday();

	std::cout << "temp worker hours:" << temp_worker.GetWorkedHours() << std::endl;
	std::cout << "contract employee non worked hours:"
		<< contract_employee.GetNonWorkedHours() << std::endl;
	std::cout << "apprentice school hours:" << apprentice.GetSchoolHours() << std::endl;

	manager.calculatePayroll();
	return 0;
}
