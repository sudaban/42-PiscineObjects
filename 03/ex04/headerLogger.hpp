#ifndef HEADERLOGGER_HPP
# define HEADERLOGGER_HPP

# include "ILogger.hpp"
# include "headerSource.hpp"

class HeaderLogger : public ILogger
{
public:
	HeaderLogger(ILogger& logger, IHeaderSource& header_source);

	virtual void write(std::string message);

private:
	ILogger& m_logger;
	IHeaderSource& m_header_source;
};

HeaderLogger::HeaderLogger(ILogger& logger, IHeaderSource& header_source)
	: m_logger(logger), m_header_source(header_source) {}

void HeaderLogger::write(std::string message)
{
	m_logger.write(m_header_source.GetHeader() + message);
}

#endif
