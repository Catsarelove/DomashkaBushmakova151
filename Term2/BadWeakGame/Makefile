myGame: Source.o SomeFunc.o

	g++ Source.o 

Source.o: People_Things.h Source.cpp 
	
	g++ -c -Wall Source.cpp

SomeFunc.o: Header1.h SomeFunc.cpp

	g++ -c -Wall SomeFunc.cpp

clean:                               
	
	rm -f myGame *.o
