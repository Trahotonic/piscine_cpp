/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUI.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:52:01 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 11:37:23 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALUI_CLASS_HPP
# define GRAPHICALUI_CLASS_HPP

#include "IMonitorDisplay.class.hpp"

class GraphicalUI : public IMonitorDisplay {
public:
	GraphicalUI();
	GraphicalUI(const GraphicalUI& graphicalUI);
	~GraphicalUI();
	GraphicalUI&	operator=(const GraphicalUI& graphicalUI);
private:
};

#endif
