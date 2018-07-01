/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetModule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:50 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/NetModule.class.hpp"

NetModule::NetModule()
{
	system("top -l 1 -n 0 | grep Networks > NetInfo");
	std::ifstream i("NetInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	int n = 0;
	while (!isdigit(total[n]))
		n++;
	total = total.substr(n, total.length());
	_curSentPackages = atoi(total.c_str());
	n = 0;
	while (total[n] != '/')
		n++;
	total = total.substr(n + 1, total.length());
	_maxSentPackages = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != ',')
		n++;
	while (!isdigit(total[n]))
		n++;
	total = total.substr(n, total.length());
	_cutRecPackages = atol(total.c_str());
	n = 0;
	while (total[n] != '/')
		n++;
	total = total.substr(n + 1, total.length());
	_maxRecPackages = atol(total.c_str()) * 1000000;
	i.close();
}

NetModule::NetModule(const NetModule& netModule) {
	*this = netModule;
}

NetModule::~NetModule() {}

NetModule&	NetModule::operator=(const NetModule& netModule) {
	if (this == &netModule)
		return (*this);
	return (*this);
}

long NetModule::getCurRecPackages()
{
	return _cutRecPackages;
}

long NetModule::getCurSentPackages()
{
	return _curSentPackages;
}

long NetModule::getMaxSentPackages()
{
	return _maxSentPackages;
}

long NetModule::getMaxRecPackages()
{
	return _maxRecPackages;
}

void NetModule::updateCurrentPackages()
{
	system("top -l 1 -n 0 | grep Networks > NetInfo");
	std::ifstream i("NetInfo");
	std::string tmp;
	std::string total = "";
	while (!i.eof())
	{
		std::getline(i, tmp);
		total += tmp;
		total += "\n";
	}
	int n = 0;
	while (!isdigit(total[n]))
		n++;
	total = total.substr(n, total.length());
	_curSentPackages = atoi(total.c_str());
	n = 0;
	while (total[n] != '/')
		n++;
	total = total.substr(n + 1, total.length());
	_maxSentPackages = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != ',')
		n++;
	while (!isdigit(total[n]))
		n++;
	total = total.substr(n, total.length());
	_cutRecPackages = atol(total.c_str());
	n = 0;
	while (total[n] != '/')
		n++;
	total = total.substr(n + 1, total.length());
	_maxRecPackages = atol(total.c_str()) * 1000000;
	i.close();
}
