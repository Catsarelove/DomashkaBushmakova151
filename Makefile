Gauss: Source.o
	g++ Source.o -o Gauss
Source.o: Header.h Source.cpp 
	g++ -c Source.cpp
clean:
	rm -f Gauss*.o
