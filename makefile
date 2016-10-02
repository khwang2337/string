str.o: str.c
	gcc str.c -o str.o

run: str.o
	./str.o

note: 
	echo "\nstr.o: str.c\n	gcc str.c -o str.o\n\nrun: str.o\n	./str.o\n"