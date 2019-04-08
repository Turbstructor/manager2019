CC = gcc
CFLAGS = -W -Wall
DBG_FLAGS = -DDEBUG
TARGET = manager
DBG_TARGET = managerDebug
OBJECTS = menu.o user.o main.o
DBG_OBJECTS = menuDebug.o userDebug.o mainDebug.o

${TARGET} : ${OBJECTS}
	${CC} ${CFLAGS} -o $@ ${OBJECTS}

${DBG_TARGET} : ${DBG_OBJECTS}
	${CC} ${CFLAGS} -o $@ ${DBG_OBJECTS}

menuDebug.o : menu.c
	${CC} ${DBG_FLAGS} -c -o $@ $^

userDebug.o : user.c
	${CC} ${DBG_FLAGS} -c -o $@ $^

mainDebug.o : main.c
	${CC} ${DBG_FLAGS} -c -o $@ $^

clean :
	rm *.o manager managerDebug
