main: main.o linkedliststack.o
	gcc -o main main.o linkedliststack.o
main.o: main.c  linkedliststack.h
	gcc -c main.c
linkedliststack.o: linkedliststack.c  linkedliststack.h
	gcc -c linkedliststack.c