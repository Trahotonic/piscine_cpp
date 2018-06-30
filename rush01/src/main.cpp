/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 10:39:19 by snikitin          #+#    #+#             */
/*   Updated: 2018/06/30 11:06:47 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ncurses.h>
# include "../inc/Controller.class.hpp"

void	throwUsage(void)
{
	std::cout << "Invalid arguments\n"
			"Possible flags: \n-a\n-u\n-c\n-r\n-n\n";
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
	initscr();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);

	char c;
	clock_t t1, t2;
	t2 = 0;
	while (1)
	{
		t1 = clock() / (CLOCKS_PER_SEC / 60);
		if (t1 <= t2)
			continue;
		t2 = clock() / (CLOCKS_PER_SEC / 60);
		clear();
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
