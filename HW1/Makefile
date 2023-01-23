all: perm

perm: permutate.o
	g++ permutate.o -o perm

permutate.o: permutate.cpp
	g++ -c permutate.cpp

clean:
	-rm *.o perm
