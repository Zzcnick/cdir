all: dir.o
	gcc -o dir.out dir.o

dir.o: dir.c
	gcc -c dir.c

run: dir.out
	./dir.out

clean:
	make -i cleanH

cleanH:
	rm *~
	rm *.out
	rm *.o
