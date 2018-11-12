#include <iostream>
#include <chrono>
#include <vector>
#define NB_MAX 100
using namespace std::chrono;

int main (int nb, char * argv[]){
    int nbMax = NB_MAX;
    if(nb < 2){
    	//nothing
    }else{
    	nbMax = std::stoi(argv[1]);
    }
    //NB_MAX will be used as an arg
    std::vector<int> vec (nbMax, 0);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for(int i = 0; i < nbMax; i++){
    	vec[i] = rand();
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<long> time_duration = duration_cast<duration<long>>(end -start);
    std::cout<< "Duration NB_MAX"<<std::endl<<time_duration.count()<<" "<<nbMax<<std::endl;
}
