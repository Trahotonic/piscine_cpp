/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:14:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:14:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_CLASS_HPP
# define CONTROLLER_CLASS_HPP

#include <ncurses.h>
#include <string>
#include "HostModule.class.hpp"
#include "CpuModule.class.hpp"
#include "NetModule.class.hpp"
#include "RamModule.class.hpp"

class Controller {
public:
	Controller();
	Controller(const Controller& controller);
	~Controller();
	Controller&	operator=(const Controller& controller);

	void	update();
	void	print();
private:
	HostModule	*_hostModule;
	CpuModule	*_cpuModule;
	NetModule	*_netModule;
	RamModule	*_ramModule;
};

#endif
