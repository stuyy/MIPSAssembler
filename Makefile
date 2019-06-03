all: main.cpp
	g++ main.cpp -o main.o && ./main.o

main: main.cpp
	g++ main.cpp -o main.o

run: main.o
	./main.o