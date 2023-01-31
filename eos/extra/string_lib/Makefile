CC=gcc 

main: main.o strcompare.o strconcat.o strcopy.o strlength.o strcharacter.o
	$(CC) -o main main.o strcompare.o strconcat.o strcopy.o strlength.o strcharacter.o
main.o: main.c 
	$(CC) -c -o main.o main.c 
strcompare.o: strcompare.c 
	$(CC) -c -o strcompare.o strcompare.c 
strconcat.o: strconcat.c 
	$(CC) -c -o strconcat.o strconcat.c 
strcopy.o: strcopy.c 
	$(CC) -c -o strcopy.o strcopy.c
strlength.o: strlength.c 
	$(CC) -c -o strlength.o strlength.c
strcharacter.o: strcharacter.c 
	$(CC) -c -o strcharacter.o strcharacter.c
lib:
	ar crv libstring.a strcompare.o strconcat.o strcopy.o strlength.o strcharacter.o
clean:
	rm -rf main.o strcompare.o strconcat.o strcopy.o strlength.o strcharacter.o main libstring.a