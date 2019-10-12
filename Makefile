#used Brandons make file to try to my first one so don't slam me if it doesn't work lol

output: main.o
	g++ -std=c++11 -Wall ./build/main.o -o./build/output.out

main.o: ./src/main.cpp
	g++ -std=c++11 -Wall -c ./src/main.cpp -o ./build/main.o


clean:
	rm ./build/*.o
	rm ./build/output.out
