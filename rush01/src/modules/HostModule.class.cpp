/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:33 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:33 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/HostModule.class.hpp"

HostModule::HostModule()
{
	char buffer[1024];
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';
	gethostname(buffer, 1023);
	_hostName = buffer;
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';
	getlogin_r(buffer, 1023);
	_userName = buffer;
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';
	system("sw_vers > OSinfo");
	std::ifstream i("OSinfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	std::size_t pos = total.find("Name:");
	_osName = total.substr(pos + 6, 8);
	pos = total.find("tVersion:");
	_osVersion = total.substr(pos + 10, getLen(pos + 9, total));
	pos = total.find("dVersion:");
	_osBuild = total.substr(pos + 10, getLen(pos + 9, total));

	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	_time = buffer;
}

HostModule::HostModule(const HostModule& hostModule) {
	*this = hostModule;
}

HostModule::~HostModule() {}

HostModule&	HostModule::operator=(const HostModule& hostModule) {
	if (this == &hostModule)
		return (*this);
	return (*this);
}

int HostModule::getLen(int n, std::string total)
{
	int ret = 0;

	while (total[n] != '\n')
	{
		ret++;
		n++;
	}
	return ret - 1;
}

std::string HostModule::getOsName()
{
	return _osName;
}

std::string HostModule::getOsVersion()
{
	return _osVersion;
}

std::string HostModule::getOsBuild()
{
	return _osBuild;
}

std::string HostModule::getTime()
{
	return _time;
}


std::string HostModule::getUserName()
{
	return _userName;
}

std::string HostModule::getHostName()
{
	return _hostName;
}

void HostModule::updateHostName()
{
	char buffer[1024];
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';
	gethostname(buffer, 1023);
	_hostName = buffer;
}

void HostModule::updateUserName()
{
	char buffer[1024];
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';
	getlogin_r(buffer, 1023);
	_userName = buffer;
}

void HostModule::updateOsBuild()
{
	system("sw_vers > OSinfo");
	std::ifstream i("OSinfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	std::size_t pos = total.find("dVersion:");
	_osBuild = total.substr(pos + 10, getLen(pos + 9, total));
}

void HostModule::updateOsName()
{
	std::ifstream i("OSinfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	std::size_t pos = total.find("Name:");
	_osName = total.substr(pos + 6, 8);
}

void HostModule::updateOsVersion()
{
	std::ifstream i("OSinfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	std::size_t pos = total.find("tVersion:");
	_osVersion = total.substr(pos + 10, getLen(pos + 9, total));
}

void HostModule::updateTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[1024];
	for (int i = 0; i < 1024; i++)
		buffer[i] = '\0';

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
	_time = buffer;
}

void HostModule::update()
{
	updateOsVersion();
	updateOsName();
	updateOsBuild();
	updateUserName();
	updateHostName();
	updateTime();
}
