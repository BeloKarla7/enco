CFLAG = -W -Wall -ansi

all: enco

enco: main.o menu.o cadastro.o
	gcc -o enco main.o menu.o cadastro.o

main.o: main.c main.h
	gcc -o main.o main.c -c

menu.o: menu.c menu.h
	gcc -o menu.o menu.c -c

cadastro.o: cadastro.c enco.h
	gcc -o cadastro.o cadastro.c -c

clean:
	rm -fr *.o
