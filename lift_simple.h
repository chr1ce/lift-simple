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
int* read_maxes();
int write_maxes(int* maxes);

const char* help_intro_str = "\nEach workout is represented by a 2-5 letter string."
                             "\nCommands are given below.\n";