/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:39:19 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 21:14:32 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ncurses.h>
# include "../inc/Controller.class.hpp"

int main(int argc, char **argv)
{
	Controller	*controller;
	try
	{
		if (argc == 1)
			throw Controller::InvalidArguments();
		controller = new Controller(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	controller->run();
	return 0;
}
