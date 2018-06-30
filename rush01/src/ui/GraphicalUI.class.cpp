/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUI.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:52:01 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 10:52:01 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicalUI.class.hpp"

GraphicalUI::GraphicalUI() {}

GraphicalUI::GraphicalUI(const GraphicalUI& graphicalUI) {
	*this = graphicalUI;
}

GraphicalUI::~GraphicalUI() {}

GraphicalUI&	GraphicalUI::operator=(const GraphicalUI& graphicalUI) {
	if (this == &graphicalUI)
		return (*this);
	return (*this);
}
