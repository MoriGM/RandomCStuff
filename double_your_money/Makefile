PROG=version1 version2 version3
OBJS=version1.o version2.o version3.o
CC=gcc
CFLAGS=-g -std=c11 -O3 -fPIC


all: ${OBJS} ${PROG}

version1: version1.o
	${CC} ${CFLAGS} -o $@ version1.o

version2: version2.o
	${CC} ${CFLAGS} -pthread -o $@ version2.o

version3: version3.o
	${CC} ${CFLAGS} -pthread -o $@ version3.o

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<
	
.PHONY: clean

clean:
	rm -f ${OBJS}
	rm -f ${PROG}
