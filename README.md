## Lift Simple

### A simple weightlifting tracker and recommendation tool

+ Query for data quickly
	+ Find how long it has been since your last deadlift PR
	+ Display your past deadlift workouts

![Screenshot from 2024-06-10 11-07-45](https://github.com/chr1ce/lift-simple/assets/108821220/1b17f148-9396-4a28-8099-ebf3169036f7)

+ Assumes knowledge of basic lifting principles
	+ Will not suggest full workouts
	+ Will not include features easily found elsewhere
		+ No timer
		+ No tracking diet
		+ Does not attempt to have features for everyone
		+ Simple workout data processing
		+ Command-line functioning, no ads, no subscription,
		data stored in a file on your machine
+ No guessing what intensity you need to work at
+ Given an understanding of past workouts and days between them,
determines recommended weight and repetitions for a given exercise
	+ Can set what percent increase you expect to see from yourself
	+ Can set how many repetitions the exercise should be

### Uses ncurses library in C

+ Cozy environment in terminal
+ Easy text-based input
+ Familiar command line interface

### Setup

#### Linux

+ Just download the liftspl executable and run it with ./liftspl in the directory
you place it in.
