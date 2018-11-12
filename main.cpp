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

    int nbCore;
    int nbMax;

    if(argc < 3)
    {
    	std::cout<<"usage : app [number of cores] [array size]"<<std::endl;
    }
    else
    {
	nbCore = std::stoi(argv[1]);
    	nbMax = std::stoi(argv[2]);
    }

    // NB_MAX will be used as an arg
    int vector1[nbMax];
    int vector2[nbMax];

    srand(time(NULL));

    for (i = 0; i < NB_MAX; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    display(vector1, nbMax);
    display(vector2, nbMax);
    
    int result[nbMax];
    

    high_resolution_clock::time_point start = high_resolution_clock::now();
    add(vector1, vector2, result, nbMax);
    high_resolution_clock::time_point end = high_resolution_clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end -start);
    std::cout << "Duration NB_MAX" << std::endl << time_duration.count() << " " << nbMax << std::endl;
    std::cout << "Addition result : " << std::endl;
    display(result, nbMax);

    high_resolution_clock::time_point sumStart = high_resolution_clock::now();
    long sumResult = sum(vector1, nbMax);
    high_resolution_clock::time_point sumEnd = high_resolution_clock::now();
    time_duration = duration_cast<nanoseconds>(sumEnd -sumStart);
    std::cout << "Duration NB_MAX" << std::endl << time_duration.count() << " " << nbMax << std::endl;
    std::cout << "Vector 1 sum result : " << sumResult << std::endl;

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

void add(int *vec1, int *vec2, int *ret, int length)
{
    int i;
    
    for (i = 0; i < length; i++)
    {
        ret[i] = vec1[i] + vec2[i];
    }
}
