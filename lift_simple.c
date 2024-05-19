#include <ncurses.h>
#include <string.h>

int main() {
	initscr();

	printw("Welcome to Lift Simple!\n");
	printw("Input commands in the form given by /help.\n");
	
	refresh();

	
	char input[20];
	getnstr(input, 20);

	if (input == NULL) {
		// Would be best to handle with reprompting
		return 0;
	}
	
	// TODO: Parse inputs and assign actions to commands


	printw("%s", input);

	refresh();

	endwin();
	
	return 0;
}
