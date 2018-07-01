/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:14:31 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 21:16:04 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_CLASS_HPP
# define CONTROLLER_CLASS_HPP

#include <ncurses.h>
#include <string>
#include "HostModule.class.hpp"
#include "CpuModule.class.hpp"
#include "NetModule.class.hpp"
#include "RamModule.class.hpp"
#include "ShellUI.class.hpp"
#include "GraphicalUI.class.hpp"

class GraphicalUI;

class Controller {
public:
	Controller();
	Controller(const Controller& controller);
	Controller(int, char **);
	~Controller();
	Controller&	operator=(const Controller& controller);

	void	update();
	void	print();

	class InvalidArguments : public virtual std::exception
	{
	public:
		InvalidArguments(void);
		InvalidArguments(InvalidArguments const & src);

		InvalidArguments &operator=(InvalidArguments const & src);

		~InvalidArguments(void) throw();

		virtual const char* what() const throw();
	};
private:
	ShellUI		*_shellUI;
	GraphicalUI *_graphicalUI;

	HostModule	*_hostModule;
	CpuModule	*_cpuModule;
	NetModule	*_netModule;
	RamModule	*_ramModule;
};

#endif
