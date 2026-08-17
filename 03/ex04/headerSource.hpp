#ifndef HEADERSOURCE_HPP
# define HEADERSOURCE_HPP

# include <string>

class IHeaderSource
{
public:
	virtual ~IHeaderSource();

	virtual std::string GetHeader() const = 0;
};

IHeaderSource::~IHeaderSource() {}

#endif
