main: main.o stack.o
	gcc -o main main.o stack.o
main.o: main.c  stack.h
	gcc -c main.c
stack.o: stack.c  stack.h
	gcc -c stack.c
