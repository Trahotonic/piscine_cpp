/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUI.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:52:01 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 21:32:50 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALUI_CLASS_HPP
# define GRAPHICALUI_CLASS_HPP

#include "IMonitorDisplay.class.hpp"
#include "Controller.class.hpp"

class Controller;

class GraphicalUI {//: public IMonitorDisplay {
public:
	GraphicalUI(Controller& controller);
	GraphicalUI(Controller& controller, int argc, char **argv);
	GraphicalUI(const GraphicalUI& graphicalUI);
	~GraphicalUI();
	GraphicalUI&	operator=(const GraphicalUI& graphicalUI);
	void	display(HostModule& hostModule);

private:
	GraphicalUI();

	Controller*	_controller;
};

#endif
