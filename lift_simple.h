#ifndef LIFT_SIMPLE_H
#define LIFT_SIMPLE_H

#include <string.h>

int main(void);


enum Workout {
    DEADLIFT,
    BENCH_PRESS,
    BARBELL_SQUAT,
    BARBELL_ROW,
    OVERHEAD_PRESS
};

const char* wkts[] = {"dl", "bp", "bbs", "bbr", "ohp"};
int len_wkts = sizeof(wkts) / sizeof(wkts[0]);

int write_workout_to_file(char* data, enum Workout workout);
char** csv_line_to_arr(char* line);
char** tokenize_input(char* input);
int what_weight();
int* read_maxes();
int write_maxes(int* maxes);

const char* help_intro_str = "\nEach workout is represented by a 2-3 letter string."
                             "\nWorkout recommendation assumes your heaviest lift is a ORM."
                             "\nCommands are given below.\n";

#endif