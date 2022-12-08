CC=gcc

main: main.o sqr.o mod.o 
	$(CC) -o main main.o sqr.o mod.o 
main.o: main.c 
	$(CC) -c -o main.o main.c 
sqr.o: sqr.c 
	$(CC) -c -o sqr.o sqr.c 
mod.o: mod.c 
	$(CC) -c -o mod.o mod.c 
clean:
	rm -rf main.o sqr.o mod.o main
