#include "Account.hpp"
#include "Bank.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

int main()
{
	Bank bank;
	
	std::cout << BLUE << "=== Creating Accounts ===" << RESET << std::endl;
	bank.create_account(100);
	bank.create_account(200);
	
	std::cout << YELLOW << "\n--- Bank State ---" << RESET << std::endl;
	std::cout << bank << std::endl;
	
	std::cout << GREEN << "Deposit to Account 0:" << RESET << std::endl;
	bank.deposit(0, 50);
	
	std::cout << GREEN << "Withdrawal from Account 1:" << RESET << std::endl;
	bank.withdraw(1, 30);
	
	std::cout << YELLOW << "\n--- Updated Bank State ---" << RESET << std::endl;
	std::cout << bank << std::endl;
	
	std::cout << RED << "Invalid Operations:" << RESET << std::endl;
	bank.deposit(-1, 50);
	bank.withdraw(0, 10000);
	
	return (0);
}