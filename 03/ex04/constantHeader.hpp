#ifndef CONSTANTHEADER_HPP
# define CONSTANTHEADER_HPP

# include <string>
# include "headerSource.hpp"

class ConstantHeader : public IHeaderSource
{
public:
	ConstantHeader(const std::string& header);

	virtual std::string GetHeader() const;

private:
	std::string m_header;
};

ConstantHeader::ConstantHeader(const std::string& header) : m_header(header) {}

std::string ConstantHeader::GetHeader() const
{
	return m_header;
}

#endif
