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
#include "../inc/HostModule.class.hpp"

Controller::Controller() : _hostModule(new HostModule), _cpuModule(new CpuModule), _netModule(new NetModule)
{}

Controller::Controller(const Controller& controller) {
	*this = controller;
}

Controller::~Controller() {}

Controller&	Controller::operator=(const Controller& controller) {
	if (this == &controller)
		return (*this);
	return (*this);
}

void Controller::update()
{
	_hostModule->update();
	_cpuModule->update();
	_netModule->updateCurrentPackages();
}

void Controller::print()
{
	float		tmpF;
	int 		tmpI;
	std::string	tmpS;
	long 		tmpL;

	mvwprintw(stdscr, 0, 0, _hostModule->getHostName().c_str());
	mvwprintw(stdscr, 1, 0, _hostModule->getUserName().c_str());
	mvwprintw(stdscr, 2, 0, _hostModule->getOsName().c_str());
	mvwprintw(stdscr, 3, 0, _hostModule->getOsVersion().c_str());
	mvwprintw(stdscr, 4, 0, _hostModule->getOsBuild().c_str());
	mvwprintw(stdscr, 5, 0, _hostModule->getTime().c_str());

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

	tmpL = _netModule->getCurSentPackages();
	tmpS = std::to_string(tmpL) + "/" + std::to_string(_netModule->getMaxSentPackages() / 1000000) + "M";
	mvwprintw(stdscr, 14, 0, tmpS.c_str());

	tmpL = _netModule->getCurRecPackages();
	tmpS = std::to_string(tmpL) + "/" + std::to_string(_netModule->getMaxRecPackages() / 1000000) + "M";
	mvwprintw(stdscr, 15, 0, tmpS.c_str());
}
