#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define PACKAGEREDUCTIONDISCOUNT_HPP

# include "command.hpp"

class PackageReductionDiscountCommand : public Command
{
public:
	PackageReductionDiscountCommand(int id, const Date& date,
		const std::string& client, const std::vector<Article>& articles);

	virtual int get_total_price() const;
};

PackageReductionDiscountCommand::PackageReductionDiscountCommand(int id,
	const Date& date, const std::string& client, const std::vector<Article>& articles)
	: Command(id, date, client, articles) {}

int PackageReductionDiscountCommand::get_total_price() const
{
	int total = Command::get_total_price();

	if (total > 150)
		return total - 10;
	return total;
}

#endif
