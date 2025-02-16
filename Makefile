include ./Make.defines

PROGS = ASCII_art

all:	${PROGS}

ASCII_art:	ASCII_art.o
		${CC} ${CFLAGS} -o $@ ASCII_art.o ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
