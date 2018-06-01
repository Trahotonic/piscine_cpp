//
// Created by Roman KYSLYY on 6/1/18.
//

#ifndef CPP_LOGGER_HPP
#define CPP_LOGGER_HPP

#include <iostream>
#include <ctime>
#include <fstream>

class   Logger
{
private:
	void            logToConsole(std::string string);
	void            logToFile(std::string string);
	std::string     makeLogEntry(std::string message);
	std::string     _file;

public:
	Logger(std::string file);

	void            log(std::string const & dest, std::string const & message);
};

#endif //CPP_LOGGER_HPP
