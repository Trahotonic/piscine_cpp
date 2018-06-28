//
// Created by Roman KYSLYY on 6/27/18.
//

#ifndef GIT_CPP_CONVERT_HPP
#define GIT_CPP_CONVERT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Convert
{
private:
	std::string		_raw;
	double 			_main;
	std::string		_char;
	std::string		_int;
	std::string 	_float;
	std::string 	_double;
public:
	Convert(void);
	Convert(Convert const & src);

	Convert(char*);

	Convert	&operator=(Convert const & src);

	~Convert(void);

	void	printChar(void);
	void	printInt(void);
	void	printFloat(void);
	void	printDouble(void);
};

#endif //GIT_CPP_CONVERT_HPP
