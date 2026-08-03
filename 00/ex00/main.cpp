#include "Account.hpp"
#include "Bank.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define CYAN	"\033[36m"
#define RESET	"\033[0m"

void header(const std::string& p_title)
{
	std::cout << std::endl << CYAN << "========================================" << std::endl;
	std::cout << " " << p_title << std::endl;
	std::cout << "========================================" << RESET << std::endl;
}

void ok(const std::string& p_msg)
{
	std::cout << GREEN << "[OK] " << RESET << p_msg << std::endl;
}

void info(const std::string& p_msg)
{
	std::cout << BLUE << "[INFO] " << RESET << p_msg << std::endl;
}

int main()
{
	Bank var_bank;

	header("Creating Accounts");
	try
	{
		var_bank.CreateAccount(100);
		ok("Account 0 created with 100");
		var_bank.CreateAccount(250);
		ok("Account 1 created with 250");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	header("Deposit Operations");
	try
	{
		var_bank.Deposit(0, 50);
		ok("Deposited 50 to account 0 (5% fee to bank)");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	header("Withdraw Operations");
	try
	{
		var_bank.Withdraw(1, 30);
		ok("Withdrew 30 from account 1");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	header("Loan Operations");
	try
	{
		var_bank.Loan(0, 5);
		ok("Loan of 5 given to account 0");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	header("Using operator[] (const getter test)");
	try
	{
		Account& var_acc = var_bank[0];
		info("Account 0 access via operator[]:");
		std::cout << "  -> " << var_acc << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	header("Error Handling Tests");
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

	header("Delete Account");
	try
	{
		var_bank.DeleteAccount(0);
		ok("Account 0 deleted (its value added to bank liquidity)");
	}
	catch (std::exception& e)
	{
		std::cout << RED << "[ERR] " << e.what() << RESET << std::endl;
	}

	std::cout << var_bank << std::endl;

	std::cout << std::endl << GREEN << "=== All tests completed ===" << RESET << std::endl;
	return 0;
}
