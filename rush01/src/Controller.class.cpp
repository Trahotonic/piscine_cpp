/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:14:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/01 10:45:11 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Controller.class.hpp"
#include "GraphicalUI.class.hpp"

Controller::Controller() : _shellUI(NULL),
 							_hostModule(NULL),
 							_cpuModule(NULL),
							_netModule(NULL),
 							_ramModule(NULL)
{}

Controller::Controller(const Controller& controller) {
	*this = controller;
}

Controller::Controller(int argc, char ** argv) : _shellUI(NULL), _hostModule(NULL), _cpuModule(NULL),
												 _netModule(NULL), _ramModule(NULL)
{
	bool host = false;
	bool cpu = false;
	bool ram = false;
	bool net = false;
	bool shell = false;
	
	_graphicalUI = new GraphicalUI(*this, argc, argv);
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
		else if (!strcmp(argv[i], "-s") && !shell)
			shell = true;
		else
			throw InvalidArguments();
	}
	if (!shell)
		throw InvalidArguments();
	if (host)
		_hostModule = new HostModule;
	if (cpu)
		_cpuModule = new CpuModule;
	if (ram)
		_ramModule = new RamModule;
	if (net)
		_netModule = new NetModule;
	if (shell)
		_shellUI = new ShellUI;
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
	_shellUI->displayField(_hostModule, _cpuModule, _ramModule, _netModule);
	_shellUI->displayHost(_hostModule);
	_shellUI->displayCpu(_cpuModule);
	_shellUI->displayNet(_netModule);
	_shellUI->displayRam(_ramModule);
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
