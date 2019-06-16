all: ./src/main.cpp
	g++ ./src/main.cpp -o ./bin/main.o && ./bin/main.o

main: ./src/main.cpp
	g++ ./src/main.cpp -o ./bin/main.o

run: main.o
	./bin/main.o