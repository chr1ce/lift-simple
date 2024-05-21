#include "lift_simple.h"
#include <ncurses.h>
#include <string.h>

int main() {
	initscr();
	setscrreg(0, 50);
	scrollok(stdscr, true);

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
		if (strcmp(input, "clear") == 0) {
			clear();
		}

		// Input data buffer for storage

		char data[30];
		char input_wkt[5];


		if (strcmp(input, "help") == 0) {
			printw("%s", help_intro_str);

			printw("\nCurrent commands:\n"
				"help: Help and documentation\n"
				"quit: Quit the application immediately\n"
				"w: Workout data management and information\n"
				"w add {wkt}: Add specified workout type to storage\n"
				"\nWorkout types:\n"
				"dl: Deadlift\n"
				"bp: Bench Press\n"
				"bbs: Barbell Squat\n"
				"bbr: Barbell Row\n"
				"ohp: Overhead Press\n");
				
		} else if (strncmp(input, "w add", 5) == 0) {
			for (int i = 0; i < 5; i++) {
					input_wkt[i] = input[6 + i];
			}
			for (int i = 0; i < len_wkts; i++) {
				int len_wkt = sizeof(wkts[i]) / sizeof(wkts[i][0]);
				
				if (strncmp(wkts[i], input_wkt, 5) == 0) {
					// Save the data to file
				}
			}
			printw("\nAdding to: %s", input_wkt);
			printw("\nEnter workout data (yyyy-mm-dd, weight, reps): ");
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
