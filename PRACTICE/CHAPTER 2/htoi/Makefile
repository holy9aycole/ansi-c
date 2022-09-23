CC=gcc
CFLAGS=-g -Wall

# Se compila con la opcion -lm para indicar al linker que enlace con la
# libreria m, es decir, libm que es donde estan implementadas las funciones
# definidas en math.h.
htoi: htoi.c
	$(CC) $(CFLAGS) -o htoi htoi.c -lm

clean:
	$(RM) htoi

#
