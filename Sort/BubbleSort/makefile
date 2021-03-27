main: main.o bubblesort.o intarray.o
	gcc -o main main.o bubblesort.o intarray.o
main.o: main.c  bubblesort.h ..\..\Utils\intarray.h
	gcc -c main.c
bubblesort.o: bubblesort.c  bubblesort.h ..\..\Utils\intarray.h
	gcc -c bubblesort.c
intarray.o: ..\..\Utils\intarray.c ..\..\Utils\intarray.h
	gcc -c ..\..\Utils\intarray.c