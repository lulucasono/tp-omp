#include "main.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

#define NB_MAX 100

using namespace std::chrono;

int main(int argc, char **argv)
{
    int i;
    
    int nbMax = NB_MAX;
    if(argc < 2)
    {
    	// nothing
    }
    else
    {
    	nbMax = std::stoi(argv[1]);
    }

    // NB_MAX will be used as an arg
    int vector1[NB_MAX];
    int vector2[NB_MAX];

    srand(time(NULL));

    for (i = 0; i < NB_MAX; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    display(vector1, NB_MAX);
    display(vector2, NB_MAX);
    
    high_resolution_clock::time_point start = high_resolution_clock::now();
    long sumResult = sum(vector1, NB_MAX);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<long> time_duration = duration_cast<duration<long>>(end -start);
    std::cout << "Duration NB_MAX" << std::endl << time_duration.count() << " " << nbMax << std::endl;
    std::cout << "Vector 1 sum : " << sumResult << std::endl;
    return 0;
}

void display(int *vec, int length)
{
    int i;
    for (i = 0; i < length; i++)
        std::cout << vec[i] << std::endl;

    std::cout << std::endl;
}

long sum(int *vec, int length)
{
    int i;
    long sum = 0;
    
    for (i = 0; i < length; i++)
    {
        sum += vec[i];
    }

    return sum;
}
