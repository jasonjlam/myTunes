all: library.o list.o main.o
  gcc -o program library.o list.o main.o

main.o: library.h list.h main.c
  gcc -c -g main.c

library.o: list.h library.c
  gcc -c -g library.c

list.o: list.c
  gcc -c -g list.c

run:
	./program

clean:
	rm *.o
