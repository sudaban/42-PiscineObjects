#include <iostream>
#include <string>
#include <vector>
#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

void PrintCommand(const Command& command)
{
	std::cout << "command " << command.GetId()
		<< " client:" << command.GetClient()
		<< " total:" << command.get_total_price() << " euros"
		<< std::endl;
}

int main()
{
	std::vector<Article> big_articles;
	big_articles.push_back(Article("keyboard", 45, 1));
	big_articles.push_back(Article("mouse", 30, 2));
	big_articles.push_back(Article("monitor", 200, 1));

	std::vector<Article> small_articles;
	small_articles.push_back(Article("pencil", 3, 5));

	Date tuesday(18, 8, 2026);
	Date wednesday(19, 8, 2026);

	Command plain(1, tuesday, "alice", big_articles);
	ThuesdayDiscountCommand tuesday_order(2, tuesday, "bob", big_articles);
	ThuesdayDiscountCommand wednesday_order(3, wednesday, "carol", big_articles);
	PackageReductionDiscountCommand big_order(4, tuesday, "dave", big_articles);
	PackageReductionDiscountCommand small_order(5, tuesday, "eve", small_articles);

	PrintCommand(plain);
	PrintCommand(tuesday_order);
	PrintCommand(wednesday_order);
	PrintCommand(big_order);
	PrintCommand(small_order);

	const Command& reference = tuesday_order;
	std::cout << "through base reference:" << reference.get_total_price() << std::endl;
	return 0;
}
