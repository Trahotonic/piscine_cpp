/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUI.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:49:47 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 11:48:40 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUI_CLASS_HPP
# define SHELLUI_CLASS_HPP

# define HOST	13
# define CPU	13
# define NET	5
# define RAM	6


#include "IMonitorDisplay.class.hpp"

class ShellUI : public virtual IMonitorDisplay {
private:
	int	_host;
	int	_cpu;
	int	_net;
	int	_ram;
	static int _cat;
public:
	ShellUI();
	ShellUI(const ShellUI& shellUI);
	~ShellUI();
	ShellUI&	operator=(const ShellUI& shellUI);

	void displayHost(HostModule *hostModule);
	void displayCpu(CpuModule *cpuModule);
	void displayRam(RamModule *ramModule);
	void displayNet(NetModule *netModule);
	void displayField(HostModule *hostModule, CpuModule *cpuModule,
						RamModule *ramModule, NetModule *netModule);
	void displayCat(void);
};

#endif
