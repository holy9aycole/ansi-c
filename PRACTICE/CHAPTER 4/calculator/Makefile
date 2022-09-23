CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lm
BINARY=main
OBJECTS=main.o getop.o stack.o getch.o

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) calculator
