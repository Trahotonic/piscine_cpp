/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:49:22 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:07 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

#include <ncurses.h>

#include "HostModule.class.hpp"
#include "CpuModule.class.hpp"
#include "RamModule.class.hpp"
#include "NetModule.class.hpp"

class IMonitorDisplay
{
public:
	//Display module??
	virtual void displayHost(HostModule *hostModule) = 0;
	virtual void displayCpu(CpuModule *cpuModule) = 0;
	virtual void displayRam(RamModule *ramModule) = 0;
	virtual void displayNet(NetModule *netModule) = 0;
	virtual ~IMonitorDisplay()
	{}
};

#endif
