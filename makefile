all: clean compile link cleanObjAndRun

compile:
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude ./src/*.cpp

link:
	g++ -g -Wall -Weffc++ -std=c++11 -o ./bin/main *.o

clean:
	rm -f ./bin/*.o

cleanObjAndRun:
	rm -f *.o
