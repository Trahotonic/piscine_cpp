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



class IMonitorDisplay {
public:
	//Display module??
	virtual void	displayHost(HostModule* hostModule);
	virtual void	displayCpu(CpuModule* cpuModule);
	virtual void	displayRam(RamModule* ramModule);
	virtual void	displayNet(NetModule* netModule);
	virtual ~IMonitorDisplay() = 0;
};

#endif
