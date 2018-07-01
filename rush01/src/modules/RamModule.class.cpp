/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:45 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:45 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/RamModule.class.hpp"

RamModule::RamModule()
{
	system("top -l 1 -n 0 | grep Phys > RAMInfo");
	std::ifstream i("RAMInfo");
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
	_used = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != '(')
		n++;
	total = total.substr(n + 1, total.length());
	_wired = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != ',')
		n++;
	total = total.substr(n + 1, total.length());
	_unused = atol(total.c_str()) * 1000000;
	i.close();
}

RamModule::RamModule(const RamModule& ramModule) {
	*this = ramModule;
}

RamModule::~RamModule() {}

RamModule&	RamModule::operator=(const RamModule& ramModule) {
	if (this == &ramModule)
		return (*this);
	return (*this);
}

long RamModule::getUsed()
{
	return _used;
}

long RamModule::getWired()
{
	return _wired;
}

long RamModule::getUnused()
{
	return _unused;
}

void RamModule::update()
{
	system("top -l 1 -n 0 | grep Phys > RAMInfo");
	std::ifstream i("RAMInfo");
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
	_used = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != '(')
		n++;
	total = total.substr(n + 1, total.length());
	_wired = atol(total.c_str()) * 1000000;
	n = 0;
	while (total[n] != ',')
		n++;
	total = total.substr(n + 1, total.length());
	_unused = atol(total.c_str()) * 1000000;
	i.close();
}
