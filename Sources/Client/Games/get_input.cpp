#include "ncurses.h"

#include "network.hpp"
#include "games.hpp"

void get_input(void)
{
	WINDOW *input_win;
	int user_input;
	int x_max;
	int y_max;

	initscr();
  	noecho();
	cbreak();

	getmaxyx(stdscr, y_max, x_max);
	input_win = newwin(3, x_max - 12, y_max - 5, 5);

	box(input_win, 0, 0);
	refresh();
	wrefresh(input_win);

	user_input = wgetch(input_win);
	// send the input to server
	std::cout << user_input << std::endl;

	getch();
	endwin();
}