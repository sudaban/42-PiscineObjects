#ifndef FILELOGGER_HPP
# define FILELOGGER_HPP

# include <fstream>
# include <string>
# include "ILogger.hpp"

class FileLogger : public ILogger
{
public:
	FileLogger(const std::string& filename);

	virtual void write(std::string message);

private:
	std::ofstream m_file;
};

FileLogger::FileLogger(const std::string& filename)
	: m_file(filename.c_str()) {}

void FileLogger::write(std::string message)
{
	m_file << message << std::endl;
}

#endif
