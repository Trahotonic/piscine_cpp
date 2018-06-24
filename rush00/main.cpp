#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include "Drop.class.hpp"
#include "Ship.class.hpp"
#include "Shot.class.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
    #define msleep(msec) Sleep(msec)
#else

#include <ctime>
#include <unistd.h>
#include <sstream>

#define msleep(msec) usleep(msec*1000)
#endif

int main()
{
	srand(time(0));
    initscr();
	curs_set(0);
    nodelay(stdscr, true);
	keypad(stdscr, true);
    use_default_colors();
    start_color();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_CYAN, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_GREEN, -1);
    unsigned char i = 0;
	unsigned int	speed = 10;
    int c;
    unsigned char timeout = 30;
	int color;
	clock_t t1, t2;
	t2 = 0;
	while (true)
	{
		t1 = clock() / (CLOCKS_PER_SEC / speed);
		if (t1 <= t2)
			continue;
		t2 = clock() / (CLOCKS_PER_SEC / speed);
		clear();
		int col = rand() % 5;
		attron(COLOR_PAIR(col));
		mvwprintw(stdscr, getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 9, "Press Space to play");
		attroff(COLOR_PAIR(col));
		mvwprintw(stdscr, 0, 0, "Press 'Q' to quit");
		c = getch();
		if (c == 32)
			break ;
		if (c == 113)
		{
			endwin();
			return 0;
		}
		refresh();
	}
	speed = 30;
    t_drops *drops = new t_drops;
    drops->drop = new Drop(getmaxx(stdscr));
    drops->next = NULL;
	Ship	*ship = new Ship;
	t_shots *shots = new t_shots;
	shots->shot = NULL;
	shots->next = NULL;
	t_shots *e_shots = new t_shots;
	e_shots->shot = NULL;
	e_shots->next = NULL;
    while ( true )
    {
		t1 = clock() / (CLOCKS_PER_SEC / speed);
		if (t1 > t2)
		{
			t2 = clock() / (CLOCKS_PER_SEC / speed);
			c = getch();
			if (c == 113)
				break ;
			clear();
			printw("Press 'Q' to exit");
			std::stringstream out;
			out << (int)(((float)(50 - speed) / 50) * 100);
			std::string s = "Speed: " + out.str();
			std::string speed_str = s + "%";

			mvwprintw(stdscr, 0, getmaxx(stdscr) / 2, ship->get_str_score().c_str());
			if (ship->get_hitPoints() >= 15)
				color = 5;
			else if (ship->get_hitPoints() >= 8)
				color = 4;
			else
				color = 1;
			attron(COLOR_PAIR(color));
			for (unsigned int k = 0; k < ship->get_hitPoints(); ++k)
				mvwprintw(stdscr, 1, getmaxx(stdscr) / 2, ship->get_str_hit_points().c_str());
			attroff(COLOR_PAIR(color));
			if (speed == 20)
			{
				mvwprintw(stdscr, 2, getmaxx(stdscr) / 2, "MAXIMUM SPEED");
			}
			else
			{
				mvwprintw(stdscr, 2, getmaxx(stdscr) / 2, speed_str.c_str());
			}

			for (int j = 0; j < getmaxx(stdscr); ++j)
				mvwprintw(stdscr, getmaxy(stdscr) / 4, j, "_");
			for (int x = 0; x < getmaxx(stdscr); ++x)
				mvwprintw(stdscr, (getmaxy(stdscr) / 2 + getmaxy(stdscr) / 4), x, "_");
			decrementX(&drops, &e_shots, *ship);
			if (c == 115 || c == KEY_DOWN)
			{
				if (ship->getY() + 1 < (getmaxy(stdscr) / 2 + getmaxy(stdscr) / 4))
					ship->setY(ship->getY() + 1);
			}
			if (c == 119 || c == KEY_UP)
			{
				if (ship->getY() - 1 > getmaxy(stdscr) / 4)
					ship->setY(ship->getY() - 1);
			}

			if (c == 32)
				ship->shoot(&shots);
			for (t_drops *ptr = drops; ptr; ptr = ptr->next)
			{
				attron(COLOR_PAIR(ptr->drop->getColor()));
				mvwprintw(stdscr, ptr->drop->getY(), ptr->drop->getX(), "<<<");
				attroff(COLOR_PAIR(ptr->drop->getColor()));
			}
			if (shots && shots->shot)
				for (t_shots *ptr = shots; ptr; ptr = ptr->next)
					mvwprintw(stdscr, ptr->shot->getY(), ptr->shot->getX(), "-");
			if (e_shots && e_shots->shot)
				for (t_shots *ptr = e_shots; ptr; ptr = ptr->next)
					mvwprintw(stdscr, ptr->shot->getY(), ptr->shot->getX(), "*");
			mvwprintw(stdscr, ship->getY() - 1, ship->getX(), ":O\\");
			mvwprintw(stdscr, ship->getY(), ship->getX(), ":>>>");
			mvwprintw(stdscr, ship->getY() + 1, ship->getX(), ":O/");
			makeFresh(&drops, getmaxx(stdscr), getmaxy(stdscr), i, &timeout);
			if (ship->get_hitPoints() == 0)
			{
				while (true)
				{
					clear();
					std::string total = "Total " + ship->get_str_score();
					attron(COLOR_PAIR(1));
					mvwprintw(stdscr, getmaxy(stdscr) / 2 ,getmaxx(stdscr) / 2 - 5, "GAME OVER");
					attroff(COLOR_PAIR(1));
					mvwprintw(stdscr, getmaxy(stdscr) / 2 + 1 ,getmaxx(stdscr) / 2 - total.length() / 2 - 1, total.c_str());
					refresh();
					c = getch();
					if (c == 113)
					{
						endwin();
						system("leaks ft_retro");
						return 0;
					}
				}
			}
			refreshShots(&shots);
			refreshShotsBack(&e_shots, *ship);
			checkCollision(&shots, &drops, *ship);
			refresh();
			if (speed < 60)
			{
				if (i % 100 == 0)
					speed++;
			}
			if (timeout)
				--timeout;
//			msleep(speed);
			i++;
		}
    }
    endwin();
	system("leaks ft_retro");
    return 0;
}
