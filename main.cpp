#include "main.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

#define NB_MAX 100

int main(int argc, char **argv)
{
    int vector1[NB_MAX];
    int vector2[NB_MAX];
    int i;

    srand(time(NULL));

    for (i = 0; i < NB_MAX; i++)
    {
        vector1[i] = rand();
        vector2[i] = rand();
    }

    display(vector1, NB_MAX);
    display(vector2, NB_MAX);

    std::cout << sum(vector1, NB_MAX) << std::endl;

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
