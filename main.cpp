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
	double vector1[nbMax];
	double vector2[nbMax];

	srand(1313);

	for (i = 0; i < nbMax; i++)
	{
		vector1[i] = (double)rand()/RAND_MAX;
		vector2[i] = (double)rand()/RAND_MAX;
	}
#ifdef MAP
	std::cout<<"vector values"<<std::endl;
	display(vector1,nbMax);
	display(vector2,nbMax);
#endif

	std::cout<<"sequential execution"<<std::endl;
	double seqResult[nbMax];
	time_point seqStart = clock::now();
	add(vector1,vector2,seqResult,nbMax);
	time_point seqEnd = clock::now();

#ifdef MAP
	std::cout<<"seq result : "<<std::endl;
	display(seqResult,nbMax);
#endif

	std::cout<<"para add"<<std::endl;
	double paraResult[nbMax];
	time_point paraAddStart = clock::now();
	paraAdd(vector1,vector2, paraResult, nbMax);
	time_point paraAddEnd = clock::now();

#ifdef MAP
	std::cout<<"para sum result : "<<std::endl;
	display(paraResult,nbMax);
#endif

	nanoseconds time_duration = duration_cast<nanoseconds>(paraAddEnd - paraAddStart);
	std::cout<<"Vector addition"<<std::endl;
	std::cout << "Duration NB_MAX cores" << std::endl << time_duration.count() << " " << nbMax << " " << nbCore << std::endl;
#ifdef MAP
	std::cout << "Addition result : " << std::endl;
	display(paraResult, nbMax);
#endif

	double sumSeq = sum(vector1,nbMax);
	std::cout<<"sum seq = "<<sumSeq<<std::endl;

	double sumPara = paraSum(vector1,nbMax);
	std::cout<<"sum para = "<<sumPara<<std::endl;

	if(cpVec(seqResult,paraResult, nbMax))
	{
		std::cout<<"Ok"<<std::endl;
	}
	else
	{
		std::cout<<"Not Ok"<<std::endl;
	}
	return 0;
}
bool cpVec(const double *vec1, const double *vec2, const int length)
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
void paraAdd( const double *vec1, const double *vec2, double *ret, const int length)
{
	int i;
	#pragma omp parallel for
	for (i = 0; i < length; i++)
	{
		ret[i] = vec1[i] + vec2[i];
	}
}
void display(double *vec, int length)
{
	int i;
	for (i = 0; i < length; i++)
		std::cout << vec[i] << std::endl;

	std::cout << std::endl;
}

double sum(double *vec, int length)
{
	int i;
	double sum = 0.0;
	for (i = 0; i < length; i++)
	{
		sum += vec[i];
	}
	return sum;
}
double paraSum(double *vec, int length)
{
	int i;
	double sum = 0;

#pragma omp parallel for shared(sum)
	for (i = 0; i < length; i++)
	{
		sum += vec[i];
	}

	return sum;
}

void add(double *vec1, double *vec2, double *ret, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		ret[i] = vec1[i] + vec2[i];
	}
}
