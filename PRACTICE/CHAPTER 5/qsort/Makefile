CC=gcc
CFLAGS=-g -Wall
BINARY=qsort
OBJECTS=main.o qsort.o readlines.o writelines.o numcmp.o atof.o

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(BINARY) $(OBJECTS)
