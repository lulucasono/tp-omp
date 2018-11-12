.PHONY: clean
clean:
	rm init main
mep: main.cpp main.h
	g++ main.cpp -o mep -DMEP=1 -fopenmp
main: main.cpp main.h
	g++ main.cpp -o main -fopenmp
