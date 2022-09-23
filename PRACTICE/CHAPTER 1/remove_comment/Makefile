CC=gcc
CFLAGS=-g -Wall

all: main

main: main.o remove_comment.o util.o
	$(CC) $(CFLAGS) -o main main.o remove_comment.o util.o

main.o: main.c ../util/util.h

remove_comment.o: remove_comment.c

util.o: ../util/util.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) main main.o remove_comment.o util.o

debug: clean main
	mkfifo pipe_file
	cat test.c > pipe_file &
	gdb ./main
