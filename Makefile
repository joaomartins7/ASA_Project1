CC = gcc
CFLAGS = -Wall

.PHONY: all clean run

all: graph

graph: gr.o main.o
	${CC} $(CFLAGS) -o vertex gr.o main.c

gr.o: gr.c gr.h
	${CC} $(CFLAGS) -o gr.o -c gr.c

main.o: main.c gr.h
	${CC} $(CFLAGS) -o main.o -c main.c


clean:
	@echo Cleaning...
	rm ./vertex *.o

run:
	./vertex 
