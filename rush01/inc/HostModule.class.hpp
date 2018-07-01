/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:32 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 21:55:54 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTMODULE_CLASS_HPP
# define HOSTMODULE_CLASS_HPP

# include <iostream>
# include <unistd.h>
# include <fstream>

class HostModule {
public:
	HostModule();
	HostModule(const HostModule& hostModule);
	~HostModule();
	HostModule&	operator=(const HostModule& hostModule);

	std::string	getHostName();
	std::string	getUserName();
	std::string	getOsName();
	std::string	getOsVersion();
	std::string	getOsBuild();
	std::string	getTime();

	void	updateHostName();
	void	updateUserName();
	void	updateOsName();
	void	updateOsVersion();
	void	updateOsBuild();
	void	updateTime();

	void	update();

	int 	getLen(int, std::string);

private:
	std::string	_hostName;
	std::string	_userName;
	std::string	_osName;
	std::string	_osVersion;
	std::string	_osBuild;
	std::string	_time;
};

#endif
