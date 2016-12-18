#pragma once

class CPiMonteCarloCalculator
{
public:
	static double CalculatePi(int iterationsCount);

private:
	static bool HitInCircle(double x, double y);
};