SOURCES = lift_simple.c
EXE = liftspl
CFLAGS = -Wall
LIBS = -lncurses
LD = gcc
OBJECTS = $(SOURCES:%.c=%.o)

default: all
all: $(EXE)

run:
	./$(EXE)
	
gdb:
	gdb ./$(EXE)

valgrind:
	valgrind ./$(EXE)

$(EXE): $(OBJECTS)
	$(LD) $(OBJECTS) -o $(EXE) $(LIBS)

clean:
	rm -f $(EXE)
	rm -f $(OBJECTS)

lift_simple.o: lift_simple.c lift_simple.h
