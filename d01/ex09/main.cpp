#include "Logger.hpp"

int main(void)
{
	Logger logger("file.txt");

	logger.log("logToConsole", "Hello World");
	return (0);
}
