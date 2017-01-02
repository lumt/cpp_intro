shrink: main.o shrink.o
	g++ -Wall main.o shrink.o -o shrink

main.o: main.cpp shrink.h
	g++ -Wall -c main.cpp

shrink.o: shrink.h shrink.cpp
	g++ -Wall -c shrink.cpp

clean:
	rm -f *.o shrink
