CC=gcc
CFLAGS=-I.

test: test.c
	gcc -o test test.c -I.
