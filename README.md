## Lift Simple

### A simple weightlifting tracker and recommendation tool

+ Query for data quickly
	+ Find how long it has been since your last deadlift PR
	+ Display your past deadlift workouts
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

#### Usage example


![image](https://github.com/chr1ce/lift-simple/assets/108821220/572c5c1c-3214-48aa-99d8-e1adb196c229)


### Uses ncurses library in C

+ Cozy environment in terminal
+ Easy text-based input
+ Familiar command line interface

### Setup

#### Linux

+ Just download the liftspl executable and run it with ./liftspl in the directory
you place it in.

 ![image](https://github.com/chr1ce/lift-simple/assets/108821220/771660a6-599f-4a1c-8301-7d3b202283cd)
