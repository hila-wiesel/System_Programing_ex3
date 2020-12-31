FLAGS= -g -Wall
CC = gcc

all: txtfind isort

txtfind: find.c
	$(CC) $(FLAGS) find.c -o txtfind

isort: sort.c
	$(CC) $(FLAGS) sort.c -o isort

.PHONY: all clean

clean:
	rm txtfind isort
