PROG=version1 version2
OBJS=version1.o version2
CC=gcc
CFLAGS=-g -std=c11 -O3 -fPIC -Wall -Wextra


all: ${OBJS} ${PROG}

version1: version1.o
	${CC} ${CFLAGS} -o $@ $^

version2: version2.o
	${CC} ${CFLAGS} -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<
	
.PHONY: clean

clean:
	rm -f ${OBJS}
	rm -f ${PROG}
