/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:48:59 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 10:48:59 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.class.hpp"

IMonitorDisplay::IMonitorDisplay() {}

IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay& iMonitorDisplay) {
	*this = iMonitorDisplay;
}

IMonitorDisplay::~IMonitorDisplay() {}

IMonitorDisplay&	IMonitorDisplay::operator=(const IMonitorDisplay& iMonitorDisplay) {
	if (this == &iMonitorDisplay)
		return (*this);
	return (*this);
}
