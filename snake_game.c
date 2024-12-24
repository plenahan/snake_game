#include<stdio.h>
#include<string.h>
#include<curses.h>

void game_init();
void game_run();
void game_end();

int main() {
	game_init();
	game_run();
	game_end();
	return 0;
}

void game_init() {
	initscr();
}

void game_run(){
	char str[2];
	mvprintw(10, 10, "S");
	refresh();
	scanw("%s", str);
       	mvprintw(10, 10, "%s", str);
	refresh();
	scanw("%s", str);
	refresh();
}

void game_end() {
	endwin();
}
