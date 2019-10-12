#used Brandons make file to try to my first one so don't slam me if it doesn't work lol

output:
	g++ -std=c++11 -Wall ./src/*.cpp -o ./build/output.out

clean:
	rm ./build/*.o
	rm ./build/output.out
