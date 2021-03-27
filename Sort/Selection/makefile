main: main.o selection.o intarray.o
	gcc -o main main.o selection.o intarray.o
main.o: main.c  selection.h ..\..\Utils\intarray.h
	gcc -c main.c
selection.o: selection.c  selection.h ..\..\Utils\intarray.h
	gcc -c selection.c
intarray.o: ..\..\Utils\intarray.c ..\..\Utils\intarray.h
	gcc -c ..\..\Utils\intarray.c