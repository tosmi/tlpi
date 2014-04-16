EXAMPLE=tee

LIBDIR=../lib
INCLUDEDIR=../lib
CC=gcc
CFLAGS=-g -Wall

libobjects := $(patsubst %.c,%.o,$(wildcard $(LIBDIR)/*.c))

compile: $(libobjects)
	$(CC) -o $(EXAMPLE) $(CFLAGS) -L$(LIBDIR) -I$(INCLUDEDIR) $(EXAMPLE).c $(libobjects)
