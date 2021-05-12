main: main.o hashtable.o
	gcc -o main main.o hashtable.o
main.o: main.c  hashtable.h
	gcc -c main.c
hashtable.o: hashtable.c  hashtable.h
	gcc -c hashtable.c