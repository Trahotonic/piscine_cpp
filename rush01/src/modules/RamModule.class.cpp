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

RamModule::RamModule() {}

RamModule::RamModule(const RamModule& ramModule) {
	*this = ramModule;
}

RamModule::~RamModule() {}

RamModule&	RamModule::operator=(const RamModule& ramModule) {
	if (this == &ramModule)
		return (*this);
	return (*this);
}


