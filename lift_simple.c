#include <ncurses.h>
#include <string.h>

int main() {
	initscr();

	printw("Welcome to Lift Simple!\n");
	printw("Input commands in the form given by /help.\n");
	printw(":: ");

	refresh();

	
	char input[20];
	getnstr(input, 20);

	if (input == NULL) {
		// Would be best to handle with reprompting
		return 0;
	}
	
	// TODO: Parse inputs and assign actions to commands
	
	if (strcmp(input, "bic -h") == 0) {
		printw("[Bi]cep [C]urls\n");
	}
		
	if (strcmp(input, "help") == 0) {
		printw("Each command is represented by a 3-5 letter string. "
			"You can add a -h flag for help and information on using "
			"a commmand like $w -h (which gives help on the "
			"commands associated with managing workout data.)\n");
		printw("Current commands:\n"
			"help: Help and documentation\n"
			"w: Workout data and information\n"
			"bic: Bicep Curls\n");
	}
	refresh();

	getch();
	endwin();
	
	return 0;
}
