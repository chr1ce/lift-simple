SOURCES = lift_simple.c
EXE = liftspl
CFLAGS = -Wall
LIBS = -lncurses
LD = gcc
OBJECTS = $(SOURCES:%.c=%.o)

default: all
all: $(EXE)
gdb:
	$(LD) $(OBJECTS) -o $(EXE) $(LIBS)
	gdb ./$(EXE)

$(EXE): $(OBJECTS)
	$(LD) $(OBJECTS) -o $(EXE) $(LIBS)
	./$(EXE)

lift_simple.o: lift_simple.c lift_simple.h