#include "stdafx.h"
#include "PiMonteCarloCalculator.h"
#include <ctime>

namespace
{

double GenerateRandomNumber()
{
	return double(rand()) / RAND_MAX;
}

}

double CPiMonteCarloCalculator::CalculatePi(int iterationsCount)
{
	srand(static_cast<unsigned>(time(NULL) % 1000));
	int hitsCount = 0;
	for (auto index = 0; index < iterationsCount; index++)
	{
		hitsCount += static_cast<int>(HitInCircle(GenerateRandomNumber(), GenerateRandomNumber()));
	}
	return 4.0 * hitsCount / iterationsCount;
}

bool CPiMonteCarloCalculator::HitInCircle(double x, double r)
{
	return (x*x + r*r) <= 1;
}
