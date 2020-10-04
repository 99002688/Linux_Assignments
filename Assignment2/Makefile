all:bitmask.o myutils.o test.o mystring.o
	gcc bitmask.o myutils.o test.o mystring.o -o all.out
	
mystring.o:
	gcc -c src/mystring.c
	
myutils.o:
	gcc -c src/myutils.c
	
bitmask.o:
	gcc -c src/bitmask.c
	
test.o:
	gcc -c test.c
	
clean:
	rm -rf *.o *.out
