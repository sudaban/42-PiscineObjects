#ifndef THUESDAYDISCOUNT_HPP
# define THUESDAYDISCOUNT_HPP

# include "command.hpp"

class ThuesdayDiscountCommand : public Command
{
public:
	ThuesdayDiscountCommand(int id, const Date& date, const std::string& client,
		const std::vector<Article>& articles);

	virtual int get_total_price() const;
};

ThuesdayDiscountCommand::ThuesdayDiscountCommand(int id, const Date& date,
	const std::string& client, const std::vector<Article>& articles)
	: Command(id, date, client, articles) {}

int ThuesdayDiscountCommand::get_total_price() const
{
	int total = Command::get_total_price();

	if (GetDate().IsTuesday())
		return total - total / 10;
	return total;
}

#endif
