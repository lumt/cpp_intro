maze: main.o maze.o
	g++ -Wall -g main.o maze.o -o maze

%.o: %.c
	g++ -Wall -g -c $<

main.o: maze.h

maze.o: maze.h

clean:
	rm -f *.o maze