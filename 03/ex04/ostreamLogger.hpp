#ifndef OSTREAMLOGGER_HPP
# define OSTREAMLOGGER_HPP

# include <ostream>
# include "ILogger.hpp"

class OstreamLogger : public ILogger
{
public:
	OstreamLogger(std::ostream& stream);

	virtual void write(std::string message);

private:
	std::ostream& m_stream;
};

OstreamLogger::OstreamLogger(std::ostream& stream) : m_stream(stream) {}

void OstreamLogger::write(std::string message)
{
	m_stream << message << std::endl;
}

#endif
