#include "vecvec.h"

#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
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
		vector1[i] = rand()%1000;
		vector2[i] = rand()%1000;
	}
#ifdef MAP
	std::cout<<"vector values"<<std::endl;
	display(vector1,nbMax);
	display(vector2,nbMax);
#endif

	std::cout<<"sequential execution"<<std::endl;
	int seqResult[nbMax];
	time_point seqStart = clock::now();
	add(vector1,vector2,seqResult,nbMax);
	time_point seqEnd = clock::now();

#ifdef MAP
	std::cout<<"seq result : "<<std::endl;
	display(seqResult,nbMax);
#endif

	std::cout<<"para add"<<std::endl;
	int paraResult[nbMax];
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

	int sumSeq = sum(vector1,nbMax);
	std::cout<<"sum seq = "<<sumSeq<<std::endl;

	int sumPara = criticalSum(vector1,nbMax);
	std::cout<<"sum para = "<<sumPara<<std::endl;

	int sumRed = reductionSum(vector1,nbMax);
	std::cout<<"sum para = "<<sumPara<<std::endl;

	if(cpVec(seqResult,paraResult, nbMax) && sumSeq==sumRed)
	{
		std::cout<<"Ok"<<std::endl;
	}
	else
	{
		std::cout<<"Not Ok"<<std::endl;
	}
	return 0;
}
