SOURCES = lift_simple.c
EXE = liftspl
CFLAGS = -Wall
LIBS = -lncurses
LD = gcc
OBJECTS = $(SOURCES:%.c=%.o)

default: all
all: $(EXE)

run:
	$(EXE)
	./$(EXE)

clean:
	$(EXE)
	./$(EXE)
	
gdb:
	$(EXE)
	gdb ./$(EXE)

valgrind:
	$(EXE)
	valgrind ./$(EXE)

$(EXE): $(OBJECTS)
	$(LD) $(OBJECTS) -o $(EXE) $(LIBS)

lift_simple.o: lift_simple.c lift_simple.h
