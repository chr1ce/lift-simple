#include "lift_simple.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main() {
	initscr();
	setscrreg(0, 50);
	scrollok(stdscr, true);
	immedok(stdscr, true);
	keypad(stdscr, TRUE);

	printw("Welcome to Lift Simple!\n");
	printw("Input commands in the form given by $help.\n");

	while (1) {
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
		} else if (strcmp(input, "clear") == 0) {
			clear();
		}

		// Input data buffer for storage

		char data[30];
		char input_wkt[5];
		enum Workout workout;
		char input_copy[20];
		strcpy(input_copy, input);
		

		char** input_tokens = tokenize_input(input_copy);


		if (strcmp(input, "help") == 0) {
			printw("%s", help_intro_str);

			printw("\nCurrent commands:\n"
				"help: Help and documentation\n"
				"quit: Quit the application immediately\n"
				"w: Workout data management and information\n"
				"w add {wkt}: Add specified workout type to storage\n"\
				"w rec {wkt} {reps}: Get recommended weight for workout"
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
					printw("\nAdding to: %s", input_wkt);
					printw("\nEnter workout data (yyyy-mm-dd, weight, reps): ");
					getnstr(data, 30);
					write_workout_to_file(data, workout);
					break;
				}
			}
		} else if (strncmp(input, "w rm", 4) == 0) {
			printw("\nEnter workout date: ");
			getnstr(data, 30);
			// Search through files for workout
		} else if (strncmp(input, "w rec", 5) == 0) {
			int reps = atoi(input_tokens[3]);
			char* input_workout = input_tokens[2];
			for (int i = 0; i < len_wkts; i++) {				
				if (strcmp(wkts[i], input_workout) == 0) {
					workout = i;
					int* maxarr = read_maxes();
					int rec_weight = what_weight(maxarr[workout], reps);
					printw("\nRecommended weight for %d repetitions: ", reps);
					printw("%d", rec_weight);
					free(maxarr);
					break;
				}
			}
		} else {
			for (int i = 0; i < len_wkts; i++) {
				int len_wkt = 3;

				if (strncmp(wkts[i], input, len_wkt) == 0) {
					workout = i;
					int* maxarr = read_maxes();

					printw("\nMax weight for %s: ", wkts[workout]);
					printw("%d", maxarr[workout]);
					free(maxarr);
					break;
				}
			}
		}

		refresh();
		
	}

	endwin();

	return 0;
}

int what_weight(int max, int reps) {
	if (reps <= 3) {
		return (int) (max * 0.95);
	} else if (reps <= 5) {
		return (int) (max * 0.90);
	} else if (reps <= 8) {
		return (int) (max * 0.80);
	} else if (reps <= 12) {
		return (int) (max * 0.75);
	} else if (reps <= 20) {
		return (int) (max * 0.60);
	}
	return 0;
}

char** tokenize_input(char* input) {
	char *pch;
	char** arr = malloc(sizeof(char*) * 5);
	if (arr == NULL) {
		exit(EXIT_FAILURE);
	}
	int i = 0;
    pch = strtok(input," ");
    while (pch != NULL) {
        arr[i] = pch;
        pch = strtok(NULL, " ");
		i++;
    }
	arr[4] = "\n";
	return arr;
}

int* read_maxes() {
	int* maxarr = malloc(len_wkts * sizeof(int));
	if (maxarr == NULL) {
		exit(EXIT_FAILURE);
	}
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
	return maxarr;
}

int write_maxes(int* maxes) {
	FILE* fp = fopen("maxes.txt", "w");
	for (int i = 0; i < len_wkts; i++) {
		fprintf(fp, "%d\n", maxes[i]);
	}
	fclose(fp);
	return 0;
}

char** csv_line_to_arr(char* line) {
	char *pch;
	char** arr = malloc(sizeof(char*) * 5);
	if (arr == NULL) {
		exit(EXIT_FAILURE);
	}
	int i = 0;
    pch = strtok(line," ,");
    while (pch != NULL) {
        arr[i] = pch;
        pch = strtok(NULL, " ,");
		i++;
    }
	arr[4] = "\n";
	return arr;
}

int write_workout_to_file(char* data, enum Workout workout) {
	FILE* fp;
	char copy[30];
	strcpy(copy, data);
	char** arrdata = csv_line_to_arr(copy);
	int* maxarr = read_maxes();

	int wl = atoi(arrdata[1]);

	if (wl > maxarr[workout]) {
		maxarr[workout] = wl;
	}
	write_maxes(maxarr);

	free(arrdata);
	free(maxarr);

	char file_name[30];

	sprintf(file_name, "%s-data.txt", wkts[workout]);
	fp = fopen(file_name, "a");
	fprintf(fp, "%s\n", data);
	fclose(fp);

	printw("\nSuccessfully saved.\n");

	return 0;
}
