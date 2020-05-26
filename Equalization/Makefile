CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -Wall

OBJ =\
	main.o\

all: main

clean:
	@echo Deleting files
	@rm -f *.o path/*.o

.c.o:
	$(CC) -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC)  $(OBJ) $(LIBS) -o run

#g++ main.cpp -o run -lsfml-graphics -lsfml-window -lsfml-system
