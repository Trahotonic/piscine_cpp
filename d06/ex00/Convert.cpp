//
// Created by Roman KYSLYY on 6/27/18.
//

#include "Convert.hpp"

Convert::Convert(void) : _char("char: "), _int("int: "), _float("float: "), _double("double: ")
{
}

Convert::Convert(Convert const &src)
{
	*this = src;
}

Convert::Convert(char * line) : _char("char: "), _int("int: "), _float("float: "), _double("double: ")
{
	_main = std::atof(line);
	if (_main == 0 && *line != '0')
	{
		_main = static_cast<double>(*line);
	}
	_raw = line;
}

Convert& Convert::operator=(Convert const &src)
{
	_char = src._char;
	_int = src._int;
	_float = src._float;
	_double = src._double;

	return *this;
}

Convert::~Convert(void)
{
}

void Convert::printChar(void)
{
	int c = static_cast<int>(_main);

	if (c > 255 || _raw.length() > 3 || c < 0)
	{
		std::cout << _char + "impossible\n";
		return ;
	}
	if (c >= 0 && c <= 32)
	{
		std::cout << _char + "Non displayable\n";
		return ;
	}
	std::cout << _char + "'" + static_cast<char>(c) + "'" << std::endl;
}

void Convert::printInt(void)
{
	long i = static_cast<long>(_main);
	if (i > 2147483647 || i < -2147483648)
	{
		std::cout << _int + "impossible" << std::endl;
		return ;
	}
	std::cout << _int << i << std::endl;
}

void Convert::printFloat(void)
{
	std::cout << std::setprecision(1) << std::fixed << _float << static_cast<float>(_main) << "f" << std::endl;
}

void Convert::printDouble()
{
	std::cout << _double << static_cast<double>(_main) << std::endl;
}