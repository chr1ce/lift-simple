#include "lift_simple.h"
#include <ncurses.h>
#include <string.h>

int main() {
	initscr();

	printw("Welcome to Lift Simple!\n");
	printw("Input commands in the form given by $help.\n");

	while (TRUE) {
		echo();
		printw("\n:: ");

		refresh();

			
		char input[20];
		getnstr(input, 20);

		if (strcmp(input, "") == 0) {
			printw("Quit the application?\n([q] to quit || any key to continue): ");
			refresh();
			int c = getch();
			if (c == 'q') {
				break;
			} else {
				continue;
			}
		}
		if (strcmp(input, "quit") == 0) {
			break;
		}

		// Input data buffer for storage

		char data[30];


		if (strcmp(input, "help") == 0) {
			printw("%s", help_intro_str);

			printw("\nCurrent commands:\n"
				"help: Help and documentation\n"
				"quit: Quit the application immediately\n"
				"w: Workout data management and information\n"
				"w add {wkt}: Add specified workout type to storage\n"
				"Workout types:\n"
				"dl: Deadlift\n"
				"bp: Bench Press\n"
				"bbs: Barbell Squat\n"
				"bbr: Barbell Row\n"
				"ohp: Overhead Press\n");
				
		} else if (strncmp(input, "w add", 5) == 0) {
			
			printw("\nEnter workout data (yyyy-mm-dd-weight-reps): ");
			getnstr(data, 30);

		} else if (strncmp(input, "w rm", 4) == 0) {
			printw("\nEnter workout date: ");
			getnstr(data, 30);
		}

		refresh();
		
	}

	endwin();

	return 0;
}

int store_workout_to_file(char* data, enum Workout workout) {

}
