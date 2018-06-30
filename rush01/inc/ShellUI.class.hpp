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

#include "IMonitorDisplay.class.hpp"

class ShellUI : public virtual IMonitorDisplay {
public:
	ShellUI();
	ShellUI(const ShellUI& shellUI);
	~ShellUI();
	ShellUI&	operator=(const ShellUI& shellUI);

	void displayHost(HostModule *hostModule);
	void displayCpu(CpuModule *cpuModule);
	void displayRam(RamModule *ramModule);
	void displayNet(NetModule *netModule);
};

#endif
