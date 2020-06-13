CC = g++
CFLAGS = -g -Wall -Wextra

Automaton.o: Automaton.h
main.o: Automaton.h

all: Automaton.o main.o
	$(CC) $(CFLAGS) Automaton.o main.o -o automaton
	$(MAKE) clean_object_files

clean_object_files:
	rm *.o

clean_results:
	rm *.txt

clean: clean_results
	rm automaton
