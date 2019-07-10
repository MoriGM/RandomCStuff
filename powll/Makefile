MAIN_OBJ=main.c.o
C_OBJ=powll.c.o
ASM_OBJ=powll.s.o
PROG_C=powllc
PROG_ASM=powllasm
CFLAGS=-g -std=c11 -O3
ASMFLAGS=-g
CC=gcc
GAS=as

all: ${PROG_C} ${PROG_ASM}

${PROG_C}: ${MAIN_OBJ} ${C_OBJ}
	${CC} ${CFLAGS} -o $@ $^

${PROG_ASM}: ${MAIN_OBJ} ${ASM_OBJ}
	${CC} ${CFLAGS} -o $@ $^

%.s.o: %.s
	${GAS} ${ASMFLAGS} -o $@ $<

%.c.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

.PHONY: clean

clean:
	rm -f ${MAIN_OBJ}
	rm -f ${C_OBJ}
	rm -f ${ASM_OBJ}
	rm -f ${PROG_C}
	rm -f ${PROG_ASM}
	
