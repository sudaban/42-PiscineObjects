#include "Bank.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

void Header(const std::string& p_title)
{
	std::cout << std::endl << CYAN << "========================================" << std::endl;
	std::cout << " " << p_title << std::endl;
	std::cout << "========================================" << RESET << std::endl;
}

void Ok(const std::string& p_msg)
{
	std::cout << GREEN << "[OK] " << RESET << p_msg << std::endl;
}

void Info(const std::string& p_msg)
{
	std::cout << BLUE << "[INFO] " << RESET << p_msg << std::endl;
}

int main()
{
	Bank var_bank;

	Header("BONUS ex00: Account nested inside Bank");
	Info("Note: Account is now Bank::Account (nested class)");

	Header("Creating Accounts");
	try
	{
		var_bank.CreateAccount(100);
		Ok("Account 0 created with 100");
		var_bank.CreateAccount(250);
		Ok("Account 1 created with 250");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	Header("Deposit Operations");
	try
	{
		var_bank.Deposit(0, 50);
		Ok("Deposited 50 to account 0 (5% fee to bank)");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	Header("Withdraw Operations");
	try
	{
		var_bank.Withdraw(1, 30);
		Ok("Withdrew 30 from account 1");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	Header("Loan Operations");
	try
	{
		var_bank.Loan(0, 5);
		Ok("Loan of 5 given to account 0");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	Header("operator[] test (no while/for loops used internally)");
	try
	{
		Info("Account 0 access via operator[]:");
		std::cout << "  -> " << var_bank[0] << std::endl;
		Info("Account 1 access via operator[]:");
		std::cout << "  -> " << var_bank[1] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	Header("Error Handling via throw/catch");
	try
	{
		var_bank.Deposit(99, 50);
	}
	catch (std::exception& e)
	{
		std::cout << YELLOW << "[EXPECTED] " << e.what() << RESET << std::endl;
	}

	try
	{
		var_bank.Withdraw(0, 99999);
	}
	catch (std::exception& e)
	{
		std::cout << YELLOW << "[EXPECTED] " << e.what() << RESET << std::endl;
	}

	try
	{
		var_bank.Loan(0, 9999999);
	}
	catch (std::exception& e)
	{
		std::cout << YELLOW << "[EXPECTED] " << e.what() << RESET << std::endl;
	}

	try
	{
		var_bank.CreateAccount(-10);
	}
	catch (std::exception& e)
	{
		std::cout << YELLOW << "[EXPECTED] " << e.what() << RESET << std::endl;
	}

	Header("Delete Account");
	try
	{
		var_bank.DeleteAccount(0);
		Ok("Account 0 deleted");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	Header("Bonus Compliance Summary");
	Info("1. Account is nested inside Bank (Bank::Account)");
	Info("2. Account has only const getters (GetId, GetValue)");
	Info("3. operator[] uses std::map::find (no while/for loops)");
	Info("4. Error management uses throw/catch");

	std::cout << std::endl << GREEN << "=== Bonus tests completed ===" << RESET << std::endl;
	return 0;
}
