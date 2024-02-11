CFLAGS := -Wall -Wextra -pedantic -std=c99
LIBS   := -lc

SRCDIR := ./src

all : sort

sort : $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean :
	rm -f sort
