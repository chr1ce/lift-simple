#include "lift_simple.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main() {
	initscr();
	setscrreg(0, 50);
	scrollok(stdscr, true);
	immedok(stdscr, true);

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
		enum Workout workout;
		int wkt_exists = 0;


		if (strcmp(input, "help") == 0) {
			printw("%s", help_intro_str);

			printw("\nCurrent commands:\n"
				"help: Help and documentation\n"
				"quit: Quit the application immediately\n"
				"w: Workout data management and information\n"
				"w add {wkt}: Add specified workout type to storage\n"
				"{wkt}: View max weight for specified workout\n"
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
				if (strncmp(wkts[i], input_wkt, 5) == 0) {
					workout = i;
					wkt_exists = 1;
					break;
				}
			}
			if (wkt_exists) {
				printw("\nAdding to: %s", input_wkt);
				printw("\nEnter workout data (yyyy-mm-dd, weight, reps): ");
				getnstr(data, 30);
				write_workout_to_file(data, workout);
			}
		} else if (strncmp(input, "w rm", 4) == 0) {
			printw("\nEnter workout date: ");
			getnstr(data, 30);
			// Search through files for workout
		} else{
			for (int i = 0; i < len_wkts; i++) {
				int len_wkt = 3;

				if (strncmp(wkts[i], input, len_wkt) == 0) {
					workout = i;
					wkt_exists = 1;
					break;
				}
			}
			if (wkt_exists) {
				FILE* fp = fopen("maxes.txt", "r");

				if (fp == NULL) {
					printw("You haven't recorded any lifts yet!");
				} else {
					int count = 0;
					int max;
					char line[6];
					while (fgets(line, sizeof line, fp) != NULL)
					{
						if (count == workout)
						{
							max = atoi(line);
						}
						else
						{
							count++;
						}
					}
					fclose(fp);

					printw("\nMax weight for %s: ", input_wkt);
					printw("%d", max);
				}
			}
		}

		refresh();
		
	}

	endwin();

	return 0;
}

int* read_maxes() {
	int maxarr[len_wkts];

	FILE* mp = fopen("maxes.txt", "r");
	if (mp == NULL) {
		FILE* maxesf = fopen("maxes.txt", "a");
		for (int i = 0; i < len_wkts; i++) {
			fprintf(maxesf, "0\n");
		}
		fclose(maxesf);
	} else {
		int count = 0;
		char line[6];
		while (fgets(line, sizeof line, mp) != NULL)
		{
			maxarr[count] = atoi(line);
			count++;
		}

		fclose(mp);
	}
}

int write_maxes() {

}

int* csv_line_to_arr(char* line) {
	char *pch;
	char** arr;
	int i = 0;
    pch = strtok (line," ,");
    while (pch = NULL) {
        arr[i] = pch;
        pch = strtok (NULL, " ,");
		i++;
    }
}

int write_workout_to_file(char* data, enum Workout workout) {
	FILE* fp;
	int arrdata[] = csv_line_to_arr(data);

	char file_name[30];

	sprintf(file_name, "%s-data.txt", wkts[workout]);
	fp = fopen(file_name, "a");
	fprintf(fp, strcat(data, "\n"));
	fclose(fp);

	return 0;
}
