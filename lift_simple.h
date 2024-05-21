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

//Should return 1 for success, 0 for failure

int store_workout_to_file(char* data, enum Workout workout);

const char* help_intro_str = "\nEach command is represented by a 3-5 letter string. "
                           "You can add a -h flag for help and information on " 
                           "a commmand like $w -h (which gives help on the "
                           "commands associated with managing workout data).\n";