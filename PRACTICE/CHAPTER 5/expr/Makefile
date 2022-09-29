CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lm
BINARY=expr
OBJECTS=expr.o stack.o

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(BINARY) $(OBJECTS)
