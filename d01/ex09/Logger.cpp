#include "Logger.hpp"

Logger::Logger(std::string file) : _file(file)
{
}

std::string Logger::makeLogEntry(std::string message)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", timeinfo);
	std::string time(buffer);

	std::string str = "[";
	str += time;
	str += "] ";
	str += message += "\n";
	return (str);
}

void Logger::logToConsole(std::string string)
{
	std::cout << makeLogEntry(string);
}

void Logger::logToFile(std::string string)
{
	std::ofstream ofs (_file, std::ofstream::app);

	ofs << makeLogEntry(string);
	ofs.close();
}

void Logger::log(const std::string &dest, const std::string &message)
{
	std::string methods[] = {
			"logToConsole",
			"logToFile"
	};
	typedef void(Logger::*meths)(std::string message);
	meths mths[] = {
			&Logger::logToConsole,
			&Logger::logToFile
	};
	int n = 0;
	while (n < 2 && methods[n] != dest)
		n++;
	if (n == 2)
	{
		std::cout << "Class Logger does not contain method \"" << dest << "\"\n";
		return ;
	}
	(this->*(mths[n]))(message);
}
