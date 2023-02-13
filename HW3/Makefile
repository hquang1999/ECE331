all: mrg

mrg: main.o mergesort.o 
	g++ main.o mergesort.o -o mrg 

main.o: main.cpp
	g++ -c main.cpp

mergesort.o: mergesort.cpp
	g++ -c mergesort.cpp 

clean:
	-rm *.o mrg
