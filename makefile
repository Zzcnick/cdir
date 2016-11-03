GCC = gcc -g

all: dir.o
	$(GCC) -o dir.out dir.o

dir.o: dir.c
	$(GCC) -c dir.c

run: dir.out
	./dir.out

clean:
	rm -f *~ *.out *.o
