

COMPILER_FLAGS = -w
LINKFLAGS=-lraylib 
INCLUDE_FLAGS=`pkg-config glib-2.0 --libs --cflags` `pkg-config --libs gmodule-2.0 `
ALL=${LINKFLAGS} ${INCLUDEFLAGS}

all: plugins
	gcc main.c  -o main ${COMPILER_FLAGS} ${LINKFLAGS} ${INCLUDE_FLAGS} \
	objects/ball.o objects/paddle.o

plugins:
	gcc objects/ball.c -shared  -o objects/ball.o  ${ALL}
	gcc objects/paddle.c -shared  -o objects/paddle.o  ${ALL}

test:
	./main

clean:
	rm -rf objects/*.o *.o main build 
