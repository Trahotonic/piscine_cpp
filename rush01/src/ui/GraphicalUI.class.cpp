/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUI.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:52:01 by snikitin          #+#    #+#             */
/*   Updated: 2018/07/01 12:04:46 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicalUI.class.hpp"
#include "HostModule.class.hpp"

GraphicalUI::GraphicalUI() {
}

GraphicalUI::GraphicalUI(Controller& controller, int argc, char **argv) 
	: _controller(&controller){

	(void)argc; (void)argv;
	//wxApp* pApp = new AppGUI();
	//wxApp::SetInstance(pApp);
	//wxEntry(argc,  argv);
}

GraphicalUI::GraphicalUI(const GraphicalUI& graphicalUI) {
	*this = graphicalUI;
}

GraphicalUI::~GraphicalUI() {}

GraphicalUI&	GraphicalUI::operator=(const GraphicalUI& graphicalUI) {
	if (this == &graphicalUI)
		return (*this);
	return (*this);
}
void	GraphicalUI::display(HostModule& hostModule) {
	(void)hostModule;
}
