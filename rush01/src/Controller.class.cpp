/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:14:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:14:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Controller.class.hpp"

Controller::Controller() : _hostModule(NULL), _cpuModule(NULL),
						   _netModule(NULL), _ramModule(NULL)
{}

Controller::Controller(const Controller& controller) {
	*this = controller;
}

Controller::Controller(int argc, char ** argv) : _hostModule(NULL), _cpuModule(NULL),
												 _netModule(NULL), _ramModule(NULL)
{
	bool host = false;
	bool cpu = false;
	bool ram = false;
	bool net = false;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i],"-a"))
		{
			host = true;
			cpu = true;
			ram = true;
			net = true;
		}
		else if (!strcmp(argv[i],"-u") && !host)
			host = true;
		else if (!strcmp(argv[i],"-c") && !cpu)
			cpu = true;
		else if (!strcmp(argv[i],"-r") && !ram)
			ram = true;
		else if (!strcmp(argv[i],"-n") && !net)
			net = true;
		else
			throw InvalidArguments();
	}
	if (host)
		_hostModule = new HostModule;
	if (cpu)
		_cpuModule = new CpuModule;
	if (ram)
		_ramModule = new RamModule;
	if (net)
		_netModule = new NetModule;
}

Controller::~Controller() {}

Controller&	Controller::operator=(const Controller& controller) {
	if (this == &controller)
		return (*this);
	return (*this);
}

void Controller::update()
{
	if (_hostModule)
		_hostModule->update();
	if (_cpuModule)
		_cpuModule->update();
	if (_netModule)
		_netModule->updateCurrentPackages();
	if (_ramModule)
		_ramModule->update();
}

void Controller::print()
{
	float		tmpF;
	int 		tmpI;
	std::string	tmpS;
	long 		tmpL;

	if (_hostModule)
	{
		mvwprintw(stdscr, 0, 0, _hostModule->getHostName().c_str());
		mvwprintw(stdscr, 1, 0, _hostModule->getUserName().c_str());
		mvwprintw(stdscr, 2, 0, _hostModule->getOsName().c_str());
		mvwprintw(stdscr, 3, 0, _hostModule->getOsVersion().c_str());
		mvwprintw(stdscr, 4, 0, _hostModule->getOsBuild().c_str());
		mvwprintw(stdscr, 5, 0, _hostModule->getTime().c_str());
	}

	if (_cpuModule)
	{
		mvwprintw(stdscr, 7, 0, _cpuModule->getModel().c_str());
		mvwprintw(stdscr, 8, 0, _cpuModule->getClockSpeed().c_str());
		tmpF = _cpuModule->getUserUsage();
		tmpS = std::to_string(tmpF);

		mvwprintw(stdscr, 9, 0, tmpS.c_str());

		tmpF = _cpuModule->getSystemUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 10, 0, tmpS.c_str());

		tmpF = _cpuModule->getIdleUsage();
		tmpS = std::to_string(tmpF);
		mvwprintw(stdscr, 11, 0, tmpS.c_str());

		tmpI = _cpuModule->getCores();
		tmpS = std::to_string(tmpI);
		mvwprintw(stdscr, 12, 0, tmpS.c_str());
	}


	if (_netModule)
	{
		tmpL = _netModule->getCurSentPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(_netModule->getMaxSentPackages() / 1000000) + "M";
		mvwprintw(stdscr, 14, 0, tmpS.c_str());

		tmpL = _netModule->getCurRecPackages();
		tmpS = std::to_string(tmpL) + "/" + std::to_string(_netModule->getMaxRecPackages() / 1000000) + "M";
		mvwprintw(stdscr, 15, 0, tmpS.c_str());
	}

	if (_ramModule)
	{
		tmpL = _ramModule->getUsed() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 17, 0, tmpS.c_str());

		tmpL = _ramModule->getWired() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 18, 0, tmpS.c_str());

		tmpL = _ramModule->getUnused() / 1000000;
		tmpS = std::to_string(tmpL) + "M";
		mvwprintw(stdscr, 19, 0, tmpS.c_str());
	}
}


Controller::InvalidArguments::InvalidArguments()
{}

Controller::InvalidArguments::InvalidArguments(InvalidArguments const &src)
{
	*this = src;
}

Controller::InvalidArguments& Controller::InvalidArguments::operator=(InvalidArguments const &src)
{
	(void)src;
	return *this;
}

Controller::InvalidArguments::~InvalidArguments() throw()
{}

const char* Controller::InvalidArguments::what() const throw()
{
	return "Invalid arguments";
}
