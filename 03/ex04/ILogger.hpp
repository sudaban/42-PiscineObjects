#ifndef ILOGGER_HPP
# define ILOGGER_HPP

# include <string>

class ILogger
{
public:
	virtual void write(std::string message) = 0;
};

#endif
