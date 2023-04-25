CC=gcc
CFLAGS=-I.

syntax: ./syntax/syntax.c
	gcc -o ./syntax/syntax ./syntax/syntax.c -I.

clock: ./clock/clock.c
	gcc -o ./clock/clock ./clock/clock.c -I.
