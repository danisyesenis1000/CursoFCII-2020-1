CC = g++
CFLAGS = -g -Wall -Wextra

jdlv.o: jdlv.h
jdlvmain.o: jdlv.h

all: jdlv.o jdlvmain.o
	$(CC) $(CFLAGS) jdlv.o jdlvmain.o -o game_of_life
	$(MAKE) clean_object_files

clean_object_files:
	rm *.o

clean: clean_object_files
	rm game_of_life
