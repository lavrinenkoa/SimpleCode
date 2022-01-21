TOPDIR = ..

BIN = bt
CC       = gcc -g -rdynamic 
LINK     = ar cr 
CFLAGS   = -Wall -O1

CFLAGS = -I/usr/include/ -I$(TOPDIR)
LIBS    = -lrt

OBJS = $(BIN).o
HS = *.c Makefile

all: $(BIN)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(BIN): $(OBJS) $(HS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

clean:
	rm -f $(OBJS) $(BIN)
