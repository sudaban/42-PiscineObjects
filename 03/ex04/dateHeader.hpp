#ifndef DATEHEADER_HPP
# define DATEHEADER_HPP

# include <ctime>
# include <iomanip>
# include <sstream>
# include <string>
# include "headerSource.hpp"

class DateHeader : public IHeaderSource
{
public:
	virtual std::string GetHeader() const;
};

std::string DateHeader::GetHeader() const
{
	std::time_t now = std::time(0);
	std::tm* local_time = std::localtime(&now);
	std::stringstream stream;

	stream << (local_time->tm_year + 1900)
		<< "-" << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
		<< "-" << std::setw(2) << std::setfill('0') << local_time->tm_mday
		<< " " << std::setw(2) << std::setfill('0') << local_time->tm_hour
		<< ":" << std::setw(2) << std::setfill('0') << local_time->tm_min
		<< ":" << std::setw(2) << std::setfill('0') << local_time->tm_sec;
	return "[" + stream.str() + "] ";
}

#endif
