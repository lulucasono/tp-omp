.PHONY: clean
clean:
	rm init main
map: main.cpp main.h
	g++ main.cpp -o mep -DMAP=1 -fopenmp
main: main.cpp main.h
	g++ main.cpp -o main -fopenmp
