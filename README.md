## Lift Simple

### A simple weightlifting tracker and recommendation tool

+ Query for data quickly
	+ Find how long it has been since your last deadlift PR
	+ Store your past deadlift workouts
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
+ Given an understanding of past workouts,
determines recommended weight and repetitions for a given exercise
	+ Can set what percent increase you expect to see from yourself
	+ Can set how many repetitions the exercise should be

#### Usage example

+ Use the $help command to see command options and syntax

 ![image](https://github.com/chr1ce/lift-simple/assets/108821220/771660a6-599f-4a1c-8301-7d3b202283cd)

 + Check current max or add a recent lift

![image](https://github.com/chr1ce/lift-simple/assets/108821220/40f7329f-fb1f-44d5-9007-df149447468a)

+ Data is saved, and will be consistent between sessions
+ Ask for a weight recommendation for a certain number of repetitions
  	+ It's OK if you forget the syntax, $help is always available and concise

![image](https://github.com/chr1ce/lift-simple/assets/108821220/d65d4e3d-9dc0-46e2-ac56-025aa1449281)

### Uses ncurses library in C

+ Cozy environment in terminal
+ Easy text-based input
+ Familiar command line interface

### Setup

#### Linux

+ Just download the liftspl executable and run it with ./liftspl in the directory
you place it in.

#### Windows

+ WSL, the Windows Subsystem for Linux, can be used to run the executable.

![image](https://github.com/chr1ce/lift-simple/assets/108821220/5318d96b-c874-48e4-92d2-4f7dacd3d31c)
