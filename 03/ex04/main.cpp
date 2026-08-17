#include <iostream>
#include <string>
#include <vector>
#include "ILogger.hpp"
#include "fileLogger.hpp"
#include "ostreamLogger.hpp"
#include "headerSource.hpp"
#include "constantHeader.hpp"
#include "dateHeader.hpp"
#include "headerLogger.hpp"

int main()
{
	std::vector<std::string> messages;
	messages.push_back("application started");
	messages.push_back("processing request");
	messages.push_back("application stopped");

	FileLogger file_logger("application.log");
	OstreamLogger console_logger(std::cout);
	ConstantHeader constant_header("[APP] ");
	DateHeader date_header;
	HeaderLogger headed_file_logger(file_logger, constant_header);
	HeaderLogger stamped_console_logger(console_logger, date_header);

	std::vector<ILogger*> loggers;
	loggers.push_back(&file_logger);
	loggers.push_back(&console_logger);
	loggers.push_back(&headed_file_logger);
	loggers.push_back(&stamped_console_logger);

	for (std::size_t i = 0; i < messages.size(); ++i)
		for (std::size_t j = 0; j < loggers.size(); ++j)
			loggers[j]->write(messages[i]);
	return 0;
}
