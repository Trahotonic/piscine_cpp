/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUI.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:49:47 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 10:49:47 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShellUI.class.hpp"

ShellUI::ShellUI() {}

ShellUI::ShellUI(const ShellUI& shellUI) {
	*this = shellUI;
}

ShellUI::~ShellUI() {}

ShellUI&	ShellUI::operator=(const ShellUI& shellUI) {
	if (this == &shellUI)
		return (*this);
	return (*this);
}
