#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <string>
# include <vector>

class Date
{
public:
	Date(int day, int month, int year);

	bool IsTuesday() const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

private:
	int m_day;
	int m_month;
	int m_year;
};

Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

bool Date::IsTuesday() const
{
	int month = m_month;
	int year = m_year;

	if (month < 3)
	{
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	int year_of_century = year % 100;
	int weekday = (m_day + 13 * (month + 1) / 5 + year_of_century
		+ year_of_century / 4 + century / 4 + 5 * century) % 7;
	return weekday == 3;
}

int Date::GetDay() const
{
	return m_day;
}

int Date::GetMonth() const
{
	return m_month;
}

int Date::GetYear() const
{
	return m_year;
}

struct Article
{
	std::string m_name;
	int m_price;
	int m_quantity;

	Article(const std::string& name, int price, int quantity);
};

Article::Article(const std::string& name, int price, int quantity)
	: m_name(name), m_price(price), m_quantity(quantity)
{
}

class Command
{
public:
	Command(int id, const Date& date, const std::string& client,
		const std::vector<Article>& articles);
	virtual ~Command();

	virtual int get_total_price() const;

	int GetId() const;
	const Date& GetDate() const;
	const std::string& GetClient() const;
	const std::vector<Article>& GetArticles() const;

private:
	int id;
	Date date;
	std::string client;
	std::vector<Article> articles;
};

Command::Command(int id, const Date& date, const std::string& client,
	const std::vector<Article>& articles)
	: id(id), date(date), client(client), articles(articles) {}

Command::~Command() {}

int Command::get_total_price() const
{
	int total = 0;

	for (std::size_t i = 0; i < articles.size(); ++i)
		total += articles[i].m_price * articles[i].m_quantity;
	return total;
}

int Command::GetId() const
{
	return id;
}

const Date& Command::GetDate() const
{
	return date;
}

const std::string& Command::GetClient() const
{
	return client;
}

const std::vector<Article>& Command::GetArticles() const
{
	return articles;
}

#endif
