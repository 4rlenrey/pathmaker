CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -g -Wall

OBJ =\
	main.o\
	path/path.o\
	functions/functions.o\
	graphical/graphical.o

all: main

clean:
	@echo Deleting files
	@rm -f *.o path/*.o Functions/*.o graphical/*.o

.c.o:
	$(CC) -g -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC) -g $(OBJ) $(LIBS) -pthread -std=c++11  -o program

#g++ main.cpp path/path.cpp -o program -lsfml-graphics -lsfml-window -lsfml-system
