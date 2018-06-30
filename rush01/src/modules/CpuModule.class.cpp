/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:41 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/CpuModule.class.hpp"

CpuModule::CpuModule()
{
	system("sysctl -n machdep.cpu.brand_string > CPUInfo");
	std::ifstream i("CPUInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	_model = total.substr(0, getNameLen(total));
	_clockspeed = total.substr(getNameLen(total) + 2, total.length());
	system("top -l 1 -n 0 | grep CPU > CPUInfo");
	std::ifstream i2("CPUInfo");
	total = "";
	while (!i2.eof())
	{
		std::getline(i2, tmp);
		total += tmp;
		total += "\n";
	}
	std::string user = total.substr(11, total.length());
	_userUsage = atof(user.c_str());
	user = user.substr(goToComma(user), user.length());
	_systemUsage = atof(user.c_str());
	user = user.substr(goToComma(user), user.length());
	_idleUsage = atof(user.c_str());
	system("sysctl -n hw.ncpu > CPUInfo");
	std::ifstream i3("CPUInfo");
	i3 >> tmp;
	_cores = atoi(tmp.c_str());
	i.close();
	i2.close();
	i3.close();
}

CpuModule::CpuModule(const CpuModule& cpuModule) {
	*this = cpuModule;
}

CpuModule::~CpuModule() {}

CpuModule&	CpuModule::operator=(const CpuModule& cpuModule) {
	if (this == &cpuModule)
		return (*this);
	return (*this);
}

int CpuModule::getNameLen(std::string total)
{
	int n = 0;
	while (total[n] != '@')
		n++;
	return n - 1;
}

int CpuModule::goToComma(std::string total)
{
	int n = 0;
	while (total[n] != ',')
		n++;
	return n + 2;
}

void CpuModule::updateModel()
{
	system("sysctl -n machdep.cpu.brand_string > CPUInfo");
	std::ifstream i("CPUInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	_model = total.substr(0, getNameLen(total));
	i.close();
}

void CpuModule::updateClockSpeed()
{
	std::ifstream i("CPUInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	_clockspeed = total.substr(getNameLen(total) + 3, total.length());
	i.close();
}

void CpuModule::updateUsage()
{
	system("top -l 1 -n 0 | grep CPU > CPUInfo");
	std::ifstream i("CPUInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	std::string user = total.substr(11, total.length());
	_userUsage = atof(user.c_str());
	user = user.substr(goToComma(user), user.length());
	_systemUsage = atof(user.c_str());
	user = user.substr(goToComma(user), user.length());
	_idleUsage = atof(user.c_str());
	i.close();
}

void CpuModule::update()
{
	updateModel();
	updateClockSpeed();
	updateUsage();
}

std::string CpuModule::getModel()
{
	return _model;
}

std::string CpuModule::getClockSpeed()
{
	return _clockspeed;
}

int CpuModule::getCores()
{
	return _cores;
}

float CpuModule::getUserUsage()
{
	return _userUsage;
}

float CpuModule::getSystemUsage()
{
	return _systemUsage;
}

float CpuModule::getIdleUsage()
{
	return _idleUsage;
}
