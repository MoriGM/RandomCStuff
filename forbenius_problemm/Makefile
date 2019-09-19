PROG=version1 version2 version3 version4
OBJS=version1.o version2.o version3.o version4.o
CC=gcc
ASM=as
LD=ld
CFLAGS=-g -std=c11 -Wall -Wextra

all: ${OBJS} ${PROG}

version%: version%.o
	${CC} ${CFLAGS} -O3 -o $@ $^
version4: version4.o
	${CC} ${CFLAGS} -O0 -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} -O3 -c -o $@ $<
%4.o: %4.c
	${CC} ${CFLAGS} -O0 -c -o $@ $<

.PHONY: clean

clean:
	rm -f ${OBJS}
	rm -f ${PROG}
