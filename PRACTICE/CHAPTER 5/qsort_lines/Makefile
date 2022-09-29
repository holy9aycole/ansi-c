CC=gcc
CFLAGS=-g -Wall
BINARY=main
OBJECTS=main.o qsort.o readlines.o writelines.o

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(BINARY) $(OBJECTS)
