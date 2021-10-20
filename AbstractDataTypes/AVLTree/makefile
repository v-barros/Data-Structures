main: main.o avltree.o linkedliststack.o
	gcc -o main main.o avltree.o linkedliststack.o
main.o: main.c  avltree.h
	gcc -c main.c
avltree.o: avltree.c  avltree.h ../LinkedListStack/linkedliststack.h
	gcc -c avltree.c
linkedliststack.o: ../LinkedListStack/linkedliststack.c ../LinkedListStack/linkedliststack.h
	gcc -c ../LinkedListStack/linkedliststack.c