CC=gcc
CFLAGS=-g -Wall

atoi: atoi.o util.o
	$(CC) $(CFLAGS) -o atoi atoi.o util.o

atoi.o: atoi.c
	$(CC) $(CFLAGS) -c atoi.c

util.o: ../util/util.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) atoi
