RBt: Source.o Source1.cpp
	g++ Source.o -o Gauss
Source.o: Header.h stack.h Source.cpp 
	g++ -c Source.cpp
Source1.o: Header.h 
	g++ -c Source.cpp
clean:
	rm -f RBt*.o
