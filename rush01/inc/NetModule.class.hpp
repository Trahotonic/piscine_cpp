/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:05:50 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 12:05:50 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETMODULE_CLASS_HPP
# define NETMODULE_CLASS_HPP

# include <iostream>
# include <fstream>
# include <string>

class NetModule {
public:
	NetModule();
	NetModule(const NetModule& netModule);
	~NetModule();
	NetModule&	operator=(const NetModule& netModule);

	long 	getCurSentPackages();
	long 	getMaxSentPackages();
	long 	getCurRecPackages();
	long 	getMaxRecPackages();

	void 	updateCurrentPackages();

private:
	long	_curSentPackages;
	long	_maxSentPackages;
	long	_cutRecPackages;
	long	_maxRecPackages;
};

#endif
