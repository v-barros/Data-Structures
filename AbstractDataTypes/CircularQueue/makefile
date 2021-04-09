main: main.o circularqueue.o
	gcc -o main main.o circularqueue.o
main.o: main.c  circularqueue.h
	gcc -c main.c
circularqueue.o: circularqueue.c  circularqueue.h
	gcc -c circularqueue.c