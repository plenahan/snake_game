#include<stdio.h>
#include<string.h>
#include<curses.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

const int RIGHT = 100;
const int LEFT = 97;
const int UP = 119;
const int DOWN = 115;
const int QUIT = 113;
const char* SNAKE = "S";

void game_init();
void game_run();
void game_end();
void generate_food();

int main() {
	game_init();
	game_run();
	game_end();
	return 0;
}

void game_init() {
	initscr();
	noecho();
	srand(time(NULL));
}

void game_run(){
	int x = COLS/2;
	int y = LINES/2;
	int snake_head_pos[2] = {y, x};
	int snake_tail_pos[2] = {y, x};
	int dir = -1;
	int curr_dir = -1;
	int food_pos[2];
	generate_food(food_pos, COLS-1, LINES-1);
	while(dir != QUIT){
		if(snake_head_pos[0] == food_pos[0] && snake_head_pos[1] == food_pos[1]){
			generate_food(food_pos, COLS-1, LINES-1);
		}
		mvprintw(snake_head_pos[0], snake_head_pos[1], SNAKE);
		refresh();
		cbreak();
		timeout(100);
		dir = getch();
		if(dir == RIGHT || dir == LEFT || dir == UP || dir == DOWN || dir == QUIT) {
			curr_dir = dir;
		}
		
		if(curr_dir == RIGHT) {
			mvprintw(snake_tail_pos[0], snake_tail_pos[1], " ");
			snake_head_pos[1]++;
			snake_tail_pos[1]++;
		}
		else if(curr_dir == LEFT) {
			mvprintw(snake_tail_pos[0], snake_tail_pos[1], " ");
			snake_head_pos[1]--;
			snake_tail_pos[1]--;
		}
		else if(curr_dir == UP) {
			mvprintw(snake_tail_pos[0], snake_tail_pos[1], " ");
			snake_head_pos[0]--;
			snake_tail_pos[0]--;
		}
		else if(curr_dir == DOWN) {
			mvprintw(snake_tail_pos[0], snake_tail_pos[1], " ");
			snake_head_pos[0]++;
			snake_tail_pos[0]++;
		}	
	}
}

void game_end() {
	endwin();
}

void generate_food(int pos[], int max_cols, int max_lines) {
	int rand_x = floor((double)(rand() * ((double) max_cols / RAND_MAX)));
	int rand_y = floor((double)(rand() * ((double) max_lines / RAND_MAX)));

	mvprintw(rand_y, rand_x, "F");
	refresh();

	pos[0] = rand_y;
	pos[1] = rand_x;
}
