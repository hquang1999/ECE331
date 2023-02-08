all: perm

perm: permutate.o sample.o
	g++ permutate.o sample.o -o perm

permutate.o: permutate.cpp
	g++ -c permutate.cpp

sample.o: sample.cpp
	g++ -c sample.cpp

clean:
	-rm *.o perm
