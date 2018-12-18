.PHONY: clean
clean:
	rm init main
map: main.cpp main.h
	g++ main.cpp -o map -DMAP=1 -fopenmp
main: main.cpp main.h
	g++ main.cpp -o main -fopenmp
