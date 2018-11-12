#include "main.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <omp.h>



using namespace std::chrono;
int main(int argc, char **argv)
{
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::high_resolution_clock::time_point time_point;
    int i;

    int nbCore;
    int nbMax;

    if(argc < 3)
    {
    	std::cout<<"usage : app [number of cores] [array size]"<<std::endl;
	return 1;
    }
    else
    {
	nbCore = std::stoi(argv[1]);
    	nbMax = std::stoi(argv[2]);
    }

    omp_set_num_threads(nbCore);
    // NB_MAX will be used as an arg
    int vector1[nbMax];
    int vector2[nbMax];

    srand(1313);

    for (i = 0; i < nbMax; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    display(vector1, nbMax);
    display(vector2, nbMax);

    int result[nbMax];

    time_point start = clock::now();
    add(vector1, vector2, result, nbMax);
    time_point end = clock::now();
    nanoseconds time_duration = duration_cast<nanoseconds>(end -start);
    std::cout<<"Vector addition"<<std::endl;
    std::cout << "Duration NB_MAX cores" << std::endl << time_duration.count() << " " << nbMax << " " << nbCore << std::endl;
    #ifdef MEP
    std::cout << "Addition result : " << std::endl;
    display(result, nbMax);
    #endif

    time_point sumStart = clock::now();
    long sumResult = sum(vector1, nbMax);
    time_point sumEnd = clock::now();
    time_duration = duration_cast<nanoseconds>(sumEnd -sumStart);
    std::cout<<"Single vector sum" << std::endl;
    std::cout << "Duration NB_MAX cores" << std::endl << time_duration.count() << " " << nbMax << " " << nbCore << std::endl;
    #ifdef MEP
    std::cout << "Vector 1 sum result : " << sumResult << std::endl;
    #endif

    std::cout<<"para add"<<std::endl;
    int paraResult[nbMax];
    time_point paraAddStart = clock::now();
    paraAdd(vector1,vector2, result, nbMax);
    time_point paraAddEnd = clock::now();
    #ifdef MEP
    display(vector1, nbMax);
    display(vector2, nbMax);
    #endif
    time_duration = duration_cast<nanoseconds>(paraAddEnd - paraAddStart);
    std::cout<<"Vector addition"<<std::endl;
    std::cout << "Duration NB_MAX cores" << std::endl << time_duration.count() << " " << nbMax << " " << nbCore << std::endl;
    #ifdef MEP
    std::cout << "Addition result : " << std::endl;
    display(paraResult, nbMax);
    #endif
    return 0;
}

void paraAdd( const int *vec1, const int *vec2, int *ret, const int length){
    #pragma omp parallel for
    for (int i = 0; i < length; i++)
    {
	ret[i] = vec1[i] + vec2[i];
    }
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
    
    #pragma omp parallel for shared(sum)
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
