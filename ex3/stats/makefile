main: main.o stats.o
	g++ -g main.o stats.o -o main

main.o: main.cpp stats.h
	g++ -Wall -g -c main.cpp

stats.o: stats.cpp stats.h
	g++ -Wall -g -c stats.cpp

clean:
	rm -f *.o execute
