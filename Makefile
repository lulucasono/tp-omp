.PHONY: clean
clean:
	rm init vecvec
map: vecvec.cpp vecvec.h
	g++ vecvec.cpp -o map -DMAP=1 -fopenmp
vecvec: vecvec.cpp vecvec.h
	g++ vecvec.cpp -o vecvec -fopenmp
