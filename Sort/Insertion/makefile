main: main.o insertion.o intarray.o
	gcc -o main main.o insertion.o intarray.o
main.o: main.c ..\..\Utils\intarray.h insertion.h
	gcc -c main.c
insertion.o: insertion.c ..\..\Utils\intarray.h insertion.h
	gcc -c insertion.c
intarray.o: ..\..\Utils\intarray.c ..\..\Utils\intarray.h
	gcc -c ..\..\Utils\intarray.c