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

void	throwUsage(void)
{
	std::cout << "Invalid arguments\n"
			"Possible flags: \n-a\n-u\n-c\n-r\n-n\n-g\n-s\n";
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		throwUsage();
		return 1;
	}
	Controller	*controller;
	try
	{
		controller = new Controller(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
//	controller->run();
	initscr();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);

	char c;
	while (1)
	{
//		clear();
//		usleep(1000000);
		controller->update();
		controller->print();
		c = getch();
		if (c == 113)
			break ;
		refresh();
	}

	endwin();
	system ("rm -f OSInfo CPUInfo NetInfo RAMInfo");

	return 0;
}
