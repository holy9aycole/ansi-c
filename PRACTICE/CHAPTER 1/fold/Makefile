CC=gcc
CFLAGS=-g -Wall
BINARY=main
OBJECTS=main.o fold.o word_procesing.o
PIPE_FILE=pipe_test

$(BINARY): $(OBJECTS)

main.o: main.c

fold: fold.c

word_procesing: word_procesing.c

clean:
	$(RM) $(BINARY) $(OBJECTS) $(PIPE_FILE)

debug: clean $(BINARY)
	mkfifo $(PIPE_FILE)
	cat ./main.c > ./$(PIPE_FILE) &
	gdb ./$(BINARY)
