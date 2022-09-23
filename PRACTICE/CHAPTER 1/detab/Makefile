CC=gcc
CFLAGS=-g -Wall
OBJS=detab.o
BINARY=detab

detab: detab.c
	$(CC) $(CFLAGS) -o detab detab.c

clean:
	@$(RM) detab
	@echo "Limpiado"

# $< contiene el nombre de la primera dependencia de una regla
# $? contiene los nombre de todas las dependencias de una regla
# $@ contiene el nombre del objetivo
