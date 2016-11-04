./project: main.o grep.o
	cc *.o -o project
main.o: main.c grep.h
	cc -g -c main.c
grep.o: grep.c grep.h
	cc -g -c grep.c
