Pendulum1: Source.o Func.o 

	g++ Source.o Func.o -o Pendulum1 

Source.o: Header.h Source.cpp
	
	g++ -c -Wall Source.cpp

Func.o: Header.h Func.cpp

	g++ -c -Wall Func.cpp

clean:                               
	
	rm -f Pendulum1 *.o
