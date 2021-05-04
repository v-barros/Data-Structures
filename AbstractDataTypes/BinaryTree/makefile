main: main.o binarytree.o linkedliststack.o
	gcc -o main main.o binarytree.o linkedliststack.o
main.o: main.c  binarytree.h
	gcc -c main.c
binarytree.o: binarytree.c  binarytree.h ..\LinkedListStack\linkedliststack.h
	gcc -c binarytree.c
linkedliststack.o: ..\LinkedListStack\linkedliststack.c ..\LinkedListStack\linkedliststack.h
	gcc -c ..\LinkedListStack\linkedliststack.c