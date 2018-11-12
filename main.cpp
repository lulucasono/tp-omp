#include <iostream>
#include <ctime>
#include <cstdlib>

#define NB_MAX 100

int main()
{
    int vector1[NB_MAX];
    int vector2[NB_MAX];
    int i;

    srand(time(NULL));

    for (i = 0; i < NB_MAX; i++)
    {
        vector1[i] = rand();
        std::cout << vector1[i] << std::endl;
        vector2[i] = rand();
        std::cout << vector2[i] << std::endl;
    }
}
