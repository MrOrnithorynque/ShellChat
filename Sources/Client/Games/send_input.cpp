/*
** SHELLCHAT PROJECT NOVEMBER 2021
** send_input.cpp :
**   Send player input.
*/

#include <ncurses.h>

#include "network.hpp"

// FUNCTION is in a thread
void send_input(void)
{
	initscr();
  	keypad(stdscr, TRUE);
	getch();

	// send the input to server
}