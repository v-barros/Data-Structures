main: main.o binarysearch.o intarray.o
	gcc -o main main.o binarysearch.o intarray.o
main.o: main.c  binarysearch.h ..\..\Utils\intarray.h
	gcc -c main.c
binarysearch.o: binarysearch.c  binarysearch.h ..\..\Utils\intarray.h
	gcc -c binarysearch.c
intarray.o: ..\..\Utils\intarray.c ..\..\Utils\intarray.h
	gcc -c ..\..\Utils\intarray.c