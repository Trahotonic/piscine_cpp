#include <ncurses.h>
#include <iostream>
#include "Drop.class.hpp"
#include "Ship.class.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
    #define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

int main()
{
    initscr();
    nodelay(stdscr, true);
    use_default_colors();
    start_color();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_CYAN, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_GREEN, -1);
    unsigned char i = 0;
    int c;
    unsigned char timeout = 30;

    t_drops *drops = new t_drops;
    drops->drop = new Drop(getmaxx(stdscr), getmaxy(stdscr));
    drops->next = NULL;
    int maxDrops;
    curs_set(0);
	Ship	*ship = new Ship;
    while ( true )
    {
        maxDrops = getmaxx(stdscr) / 20;
        c = getch();
        if (c == 113)
            break ;
        clear();
        printw("Press 'Q' to exit");
        printw("\n%d", maxDrops);
        printw("\n\n%d", drops->drop->getTotalDrops());
        printw("\n\n\n%d", c);
        decrementX(drops);
		if (c == 115)
			ship->setY(ship->getY() + 1);
		if (c == 119)
			ship->setY(ship->getY() - 1);
        for (t_drops *ptr = drops; ptr; ptr = ptr->next)
        {
            attron(COLOR_PAIR(ptr->drop->getColor()));
            mvwprintw(stdscr, ptr->drop->getY(), ptr->drop->getX(), "<<<");
            attroff(COLOR_PAIR(ptr->drop->getColor()));
        }
		mvwprintw(stdscr, ship->getY(), ship->getX(), ">");
        makeFresh(drops, getmaxx(stdscr), getmaxy(stdscr), maxDrops, i, &timeout);
        refresh();
        if (timeout)
            --timeout;
        msleep(50);
        i++;
    }

    endwin();
    return 0;
}