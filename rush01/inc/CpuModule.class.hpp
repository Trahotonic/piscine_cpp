/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:41 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:09:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>

class CpuModule {
public:
	CpuModule();
	CpuModule(const CpuModule& cpuModule);
	~CpuModule();
	CpuModule&	operator=(const CpuModule& cpuModule);

	std::string getModel();
	std::string getClockSpeed();
	int			 getCores();
	float 		getUserUsage();
	float 		getSystemUsage();
	float 		getIdleUsage();

	void		updateModel();
	void		updateClockSpeed();
	void		updateUsage();

	void		update();

	int 	getNameLen(std::string total);
	int 	goToComma(std::string total);

private:
	std::string _model;
	std::string _clockspeed;
	int 		_cores;
	float 		_userUsage;
	float		_systemUsage;
	float		_idleUsage;
};

#endif
