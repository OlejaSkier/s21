CC=gcc
CFLAGS=-Wall -Werror -Wextra
DIR=../build

all: graph.o draw.o stack.o
	$(CC) $(FLAGS) $(DIR)/graph.o $(DIR)/draw.o $(DIR)/stack.o -o $(DIR)/graph
	make clean

graph.o: graph.c
	gcc $(CFLAGS) -c graph.c -o $(DIR)/graph.o

draw.o: draw.c
	gcc $(CFLAGS) -c draw.c -o $(DIR)/draw.o

stack.o: stack.c
	gcc $(CFLAGS) -c stack.c -o $(DIR)/stack.o

clean:
	rm -rf $(DIR)/*.o
	rm -rf *.out