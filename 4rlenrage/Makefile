CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -g -Wall
CODE_L = src

OBJ =\
	${CODE_L}/*.cpp\
	${CODE_L}/*/*.cpp


all: main

clean:
	@echo Deleting files
	@rm -f *.o ${CODE_L}/*.o ${CODE_L}/*/*.o Generated/*.png

.c.o:
	$(CC) -g -c $(INCLUDES) $(FLAGS) $<

main: $(OBJ)
	$(CC) -g $(OBJ) $(LIBS) -std=c++11  -o run
	make clean