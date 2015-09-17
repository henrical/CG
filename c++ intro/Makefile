all:
	(rm -f main *.o)
	(g++ -c animal.cpp)
	(g++ -c cat.cpp)
	(g++ -c dog.cpp)
	(g++ -c main.cpp)
	(g++ -ansi -Wall -o main main.o dog.o cat.o animal.o -lm)
clean: 
	(rm -f main *.o)
	
	
	
	