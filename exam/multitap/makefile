multitap: main.o multitap.o
	g++ -Wall -g main.o multitap.o -o multitap

%.o: %.c
	g++ -Wall -g -c $<

main.o: multitap.h

multitap.o: multitap.h

clean:
	rm -f *.o multitap