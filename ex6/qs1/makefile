main: q1.cpp
	g++ -Wall -g q1.cpp IntegerArray.cpp -o main

q1.o: q1.cpp IntegerArray.h
	g++ -Wall -g -c q1.cpp

IntegerArray.o: IntegerArray.cpp IntegerArray.h
	g++ -Wall -g -c IntegerArray.cpp

clean:
	rm -f *.o main