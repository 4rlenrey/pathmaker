CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -Wall

OBJ =\
	main.o\
	path/path.o

all: main

clean:
	@echo Deleting files
	@rm -f *.o path/*.o

.c.o:
	$(CC) -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC)  $(OBJ) $(LIBS) -o program

#g++ main.cpp path/path.cpp -o program -lsfml-graphics -lsfml-window -lsfml-system
