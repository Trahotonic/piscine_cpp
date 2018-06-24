#include <ctime>
#include <unistd.h>
#include <sstream>
#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include "Drop.class.hpp"
#include "Ship.class.hpp"
#include "Shot.class.hpp"

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
	unsigned int	speed = 20;
	bool			multiplayer = false;
    int c;
    unsigned char timeout = 30;
	std::string on_off = "OFF";
	int color;
	int col;
	int	menu = 0;
	std::string menus[] = {
			"     Easy",
			"    Medium",
			"   Hardcore"
	};
	clock_t t1, t2;
	t2 = 0;
	while (true)
	{
		t1 = clock() / (CLOCKS_PER_SEC / speed);
		if (t1 <= t2)
			continue;
		t2 = clock() / (CLOCKS_PER_SEC / speed);
		clear();
		c = getch();
		col = rand() % 5;
		attron(COLOR_PAIR(col));
		mvwprintw(stdscr, getmaxy(stdscr) / 2, getmaxx(stdscr) / 2 - 9, "Press Space to play");
		attroff(COLOR_PAIR(col));
		if (c == 109 && multiplayer == false)
		{
			multiplayer = true;
			on_off = "ON";
		}
		else if (c == 109 && multiplayer == true)
		{
			multiplayer = false;
			on_off = "OFF";
		}
		mvwprintw(stdscr, getmaxy(stdscr) / 2 + 10, getmaxx(stdscr) / 2 - 7, "Multiplayer ");
		if (multiplayer)
			attron(COLOR_PAIR(5));
		if (!multiplayer)
			attron(COLOR_PAIR(1));
		mvwprintw(stdscr, getmaxy(stdscr) / 2 + 10, getmaxx(stdscr) / 2 + 6, on_off.c_str());
		if (multiplayer)
			attroff(COLOR_PAIR(5));
		if (!multiplayer)
			attroff(COLOR_PAIR(1));
		if (c == KEY_UP && menu > 0)
			--menu;
		if (c == KEY_DOWN && menu < 2)
			++menu;
		col = rand() % 5;
		for (int j = 0; j < 3; ++j)
		{
			if (menu == 0 && j == 0)
				attron(COLOR_PAIR(5));
			if (menu == 1 && j == 1)
				attron(COLOR_PAIR(4));
			if (menu == 2 && j == 2)
				attron(COLOR_PAIR(col));
			mvwprintw(stdscr, getmaxy(stdscr) / 2 + 3 + j, getmaxx(stdscr) / 2 - 6, menus[j].c_str());
			if (menu == 0 && j == 0)
				attroff(COLOR_PAIR(5));
			if (menu == 1 && j == 1)
				attroff(COLOR_PAIR(4));
			if (menu == 2 && j == 2)
				attroff(COLOR_PAIR(col));
		}
		mvwprintw(stdscr, 0, 0, "Press 'Q' to quit");
		if (c == 32)
		{
			if (menu == 0)
				speed = 20;
			if (menu == 1)
				speed = 40;
			if (menu == 2)
				speed = 70;
			break ;
		}
		if (c == 113)
		{
			endwin();
			return 0;
		}
		refresh();
	}
    t_drops *drops = new t_drops;
    drops->drop = new Drop(getmaxx(stdscr));
    drops->next = NULL;
	Ship	*ship = NULL;
	Ship	*ship2 = NULL;
	if (multiplayer)
	{
		ship = new Ship(getmaxy(stdscr) / 3);
		ship2 = new Ship(getmaxy(stdscr) / 3 + getmaxy(stdscr) / 3);
	}
	else
		ship = new Ship;
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
			if (!multiplayer)
			{
				if (ship->get_hitPoints() >= 15)
					color = 5;
				else if (ship->get_hitPoints() >= 8)
					color = 4;
				else
					color = 1;
				attron(COLOR_PAIR(color));
				mvwprintw(stdscr, 1, getmaxx(stdscr) / 2, ship->get_str_hit_points().c_str());
				attroff(COLOR_PAIR(color));
			}
			else
			{
				std::string score;
				if (ship->get_hitPoints() >= 15)
					color = 5;
				else if (ship->get_hitPoints() >= 8)
					color = 4;
				else
					color = 1;
				if (ship->get_hitPoints() <= 0)
				{
					attron(COLOR_PAIR(color));
					mvwprintw(stdscr, 1, getmaxx(stdscr) / 2, "DEAD");
					attroff(COLOR_PAIR(color));
				}
				else
				{
					score = "P1 " + ship->get_str_hit_points();
					attron(COLOR_PAIR(color));
					mvwprintw(stdscr, 1, getmaxx(stdscr) / 2, score.c_str());
					attroff(COLOR_PAIR(color));
				}
				if (ship2->get_hitPoints() >= 15)
					color = 5;
				else if (ship2->get_hitPoints() >= 8)
					color = 4;
				else
					color = 1;
				if (ship2->get_hitPoints() <= 0)
				{
					attron(COLOR_PAIR(color));
					mvwprintw(stdscr, 2, getmaxx(stdscr) / 2, "DEAD");
					attroff(COLOR_PAIR(color));
				}
				else
				{
					score = "P2 " + ship2->get_str_hit_points();
					attron(COLOR_PAIR(color));
					mvwprintw(stdscr, 2, getmaxx(stdscr) / 2, score.c_str());
					attroff(COLOR_PAIR(color));
				}
			}
			if (speed == 20)
				mvwprintw(stdscr, 3, getmaxx(stdscr) / 2, "MAXIMUM SPEED");
			else
				mvwprintw(stdscr, 3, getmaxx(stdscr) / 2, speed_str.c_str());

			for (int j = 0; j < getmaxx(stdscr); ++j)
				mvwprintw(stdscr, getmaxy(stdscr) / 4, j, "_");
			for (int x = 0; x < getmaxx(stdscr); ++x)
				mvwprintw(stdscr, (getmaxy(stdscr) / 2 + getmaxy(stdscr) / 4), x, "_");
			decrementX(&drops, &e_shots, *ship, ship2);
			if (c == 115)
			{
				if (ship->getY() + 1 < (getmaxy(stdscr) / 2 + getmaxy(stdscr) / 4))
					ship->setY(ship->getY() + 1);
			}
			if (c == 119)
			{
				if (ship->getY() - 1 > getmaxy(stdscr) / 4)
					ship->setY(ship->getY() - 1);
			}
			if (ship2 && c == KEY_DOWN)
			{
				if (ship2->getY() + 1 < (getmaxy(stdscr) / 2 + getmaxy(stdscr) / 4))
					ship2->setY(ship2->getY() + 1);
			}
			if (ship2 && c == KEY_UP)
			{
				if (ship2->getY() - 1 > getmaxy(stdscr) / 4)
					ship2->setY(ship2->getY() - 1);
			}
			if (c == 32)
				ship->shoot(&shots);
			if (c == '\n')
				ship2->shoot(&shots);
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
			if (ship->get_hitPoints() > 0)
			{
				mvwprintw(stdscr, ship->getY() - 1, ship->getX(), ":O\\");
				mvwprintw(stdscr, ship->getY(), ship->getX(), ":>>>");
				mvwprintw(stdscr, ship->getY() + 1, ship->getX(), ":O/");
			}
			if (multiplayer && ship2->get_hitPoints() > 0)
			{
				mvwprintw(stdscr, ship2->getY() - 1, ship2->getX(), "--");
				mvwprintw(stdscr, ship2->getY(), ship2->getX(), "-ooo");
				mvwprintw(stdscr, ship2->getY() + 1, ship2->getX(), "--");
			}
			makeFresh(&drops, getmaxx(stdscr), getmaxy(stdscr), i, &timeout);
			if (ship->get_hitPoints() == 0 && ship2 && ship2->get_hitPoints() == 0)
			{
				clear();
				while (true)
				{
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
						return 0;
					}
				}
			}
			refreshShots(&shots);
			refreshShotsBack(&e_shots, *ship);
			checkCollision(&shots, &drops, *ship);
			if (multiplayer)
			{
				refreshShotsBack(&e_shots, *ship2);
				checkCollision(&shots, &drops, *ship2);
			}
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
    return 0;
}
