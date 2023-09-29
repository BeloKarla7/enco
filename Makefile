CFLAG = -W -Wall -ansi

all: enco

enco: main.o menu.o conta.o transacao.o
	gcc -o enco main.o menu.o conta.o transacao.o

main.o: main.c main.h
	gcc -o main.o main.c -c

menu.o: menu.c menu.h
	gcc -o menu.o menu.c -c

conta.o: conta.c conta.h enco.h
	gcc -o conta.o conta.c -c

transacao.o: transacao.c transacao.h enco.h
	gcc -o transacao.o transacao.c -c

clean:
	rm -fr *.o
