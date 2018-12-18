#include "vecvec.h"

#include <ctime>
#include <cstdlib>
#include <omp.h>



bool cpVec(const int *vec1, const int *vec2, const int length)
{
	for(int i = 0 ; i< length; i++)
	{
		if(vec1[i] != vec2[i])
		{
			return false;
		}
	}
	return true;
}
void paraAdd( const int *vec1, const int *vec2, int *ret, const int length)
{
	int i;
	#pragma omp parallel for
	for (i = 0; i < length; i++)
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

int sum(int *vec, int length)
{
	int i;
	int sum = 0.0;
	for (i = 0; i < length; i++)
	{
		sum += vec[i];
	}
	return sum;
}
int paraSum(int *vec, int length)
{
	int i;
	int sum = 0;

#pragma omp parallel for shared(sum)
	for (i = 0; i < length; i++)
	{
		sum += vec[i];
		//race condition :)
	}

	return sum;
}

//no race condition, but we should measure execution time
int criticalSum(int *vec, int length)
{
	int i;
	int sum = 0;

#pragma omp parallel for shared(sum)
	for (i = 0; i < length; i++)
	{
		#pragma omp critical
		sum += vec[i];
	}

	return sum;
}

int reductionSum(int *vec, int length)
{
	int i;
	int sum = 0;

#pragma omp parallel for reduction(+:sum)
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
