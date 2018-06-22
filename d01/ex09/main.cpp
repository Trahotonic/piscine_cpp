#include "Logger.hpp"

int main(void)
{
	Logger logger("file.txt");

	logger.log("logToFile", "Hello World");
	return (0);
}
