PROG=version1 version2 version3 version4 version5 version6 version7
CC=gcc
CFLAGS= -g -std=c11 -O3

all: ${PROG}

version%: version%.c
	${CC} ${CFLAGS} -o $@ $< -lm

.PHONY: clean

clean:
	rm -rf ${PROG}
	
