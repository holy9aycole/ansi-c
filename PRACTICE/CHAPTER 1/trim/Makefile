CC=gcc
CFLAGS=-g -Wall
BINARY=trim
OBJECTS=trim.o util.o

all=trim

trim: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS)

trim.o: trim.c
	$(CC) $(CFLAGS) -c trim.c -o trim.o

util.o: ../util/util.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BINARY) $(OBJECTS)
