CFLAGS := -Wall -Wextra -pedantic -std=c99
LIBS   := -lc

SRCDIR := ./src

SRC = $(wildcard $(SRCDIR)/*.c)

all : sort

sort : $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean :
	rm -f sort
