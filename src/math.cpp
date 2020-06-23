#include <vector>
#include <iostream>
#include <math.h>

#include "math.h"
#include "cpu.h"
#include "inputOutput.h"

CS417_SP::Math::Math()
{
}

CS417_SP::Math::~Math()
{
}

void CS417_SP::Math::piecewiseLinearInterpolation(CPU &cpuProfile)
{
	double dx;
	double dy;
	double m;
	double y0;
	double x0;
	double x1;
	int cores = cpuProfile.getNumCores();

	for (int core = 0; core < cores; ++core)
	{
		for (int interval = 0; interval < cpuProfile.getNumIntervals() - 1; ++interval)
		{
			dy = (cpuProfile.getCoreTemperatureAtInterval((interval+1), core) - cpuProfile.getCoreTemperatureAtInterval(interval, core));
			dx = cpuProfile.getIntervalTime();
			m = dy / dx;
			y0 = cpuProfile.getCoreTemperatureAtInterval(interval, core);
			x0 = dx * interval;
			x1 = dx * (interval + 1);

			cpuProfile.logLinearInterpData(x0, x1, y0, m);
		}
	}
}

void CS417_SP::Math::linearLeastSquares(CPU & cpuProfile)
{
	int cores = cpuProfile.getNumCores();
	int numIntervals = cpuProfile.getNumIntervals() - 1;
	double yn;
	double xn;

	double m;     // 
	double b;     // 
	double x0;    // 
	double x1;    // 

	// For each core, generate an X matrix and Y vector.
	// Matrix X is an m*n matrix where m is the number of intervals and n is 2;
	for (int core = 0; core < cores; ++core)
	{
		Eigen::MatrixXd X;
		Eigen::MatrixXd Y;

		//TODO: Get rid of these horrible hard-coded resize params 
		//    Debug why MatrixXd.resize(index, index) throws exceptions with dynamic indexes.
		//    Note: both g++ and clang will compile but produce the "Invalid sizes when resizing a matrix or array."' exception at runtime.
		//        Compiled code from VS2017 using visual C++ works fine, oddly enough.
		X.resize(2000, 2);
		Y.resize(2000, 1);
		


		for (int interval = 0; interval < numIntervals; ++interval)
		{
			yn = cpuProfile.getCoreTemperatureAtInterval(interval, core);
			xn = interval * cpuProfile.getIntervalTime();

			Y(interval) = yn;
			X(interval, 0) = 1.00;
			X(interval, 1) = xn;
		}

		// Evaluate the solution to X and Y using QR decomposition.
		Eigen::MatrixXd t = X.colPivHouseholderQr().solve(Y);

		x0 = 0.0;
		x1 = (cpuProfile.getNumIntervals() * cpuProfile.getIntervalTime());
		b = t.coeff(0, 0);
		m  = t.coeff(1, 0);

		// Log the Linear Least Squares solution. 
		cpuProfile.logLLSQData(x0, x1, b, m);
	}
}