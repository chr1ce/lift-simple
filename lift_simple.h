#include <string.h>

int main(void);


enum Workout {
    BENCH_PRESS,
    DEADLIFT,
    BARBELL_SQUAT,
    OVERHEAD_PRESS,
    BARBELL_ROW
};

//Should return 1 for success, 0 for failure

int store_workout_to_file(char* data, enum Workout workout);

const char* help_intro_str = "\nEach command is represented by a 3-5 letter string."
                           "You can add a -h flag for help and information on " 
                           "a commmand like $w -h (which gives help on the "
                           "commands associated with managing workout data).\n";