#include <iostream>
#include <chrono>
#include <vector>
#define NB_MAX 100
using namespace std::chrono;

int main (int nb, char * argv[]){
    typedef std::chrono::high_resolution_clock clock;
    int nbMax = NB_MAX;
    if(nb < 2){
    	//nothing
    }else{
    	nbMax = std::stoi(argv[1]);
    }
    //NB_MAX will be used as an arg
    std::vector<int> vec (nbMax, 0);
    clock::time_point start = clock::now();
    for(int i = 0; i < nbMax; i++){
    	vec[i] = rand();
    }
    clock::time_point end = clock::now();
    std::chrono::nanoseconds time_duration = duration_cast<std::chrono::nanoseconds>(end -start);
    std::cout<< "Duration NB_MAX"<<std::endl<<time_duration.count()<<" "<<nbMax<<std::endl;
}
