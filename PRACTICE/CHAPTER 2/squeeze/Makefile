CC=gcc
CFLAGS=-g -Wall
BINARY=squeeze
OBJECTS=squeeze.o util.o

squeeze: $(OBJECTS)
	$(CC) $(CFLAGS) -o squeeze $(OBJECTS)

squeeze.o: squeeze.c
	$(CC) $(CFLAGS) -c $<

util.o: ../util/util.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(BINARY) $(OBJECTS)
