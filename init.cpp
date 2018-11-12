#include <iostream>
#include <chrono>
#include <vector>
#define NB_MAX 100
int main (){
    using namespace std::chrono;
    //NB_MAX will be used as an arg
    std::vector<int> vec (NB_MAX, 0);
    high_resolution_clock::time_point start = high_resolution_clock::now();
    for(int i = 0; i < NB_MAX; i++){
    	vec[i] = rand();
    }
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<long> time_duration = duration_cast<duration<long>>(end -start);
    std::cout<< "Duration NB_MAX"<<std::endl<<time_duration.count()<<NB_MAX<<std::endl;
}
