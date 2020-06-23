#include <iostream>
#include <fstream>
#include <string.h>

#include "inputOutput.h"
#include "math.h"
#include "cpu.h"

using namespace CS417_SP;

int main(int argc, char* argv[])
{
	if (!(argc > 1))
	{
		std::cout << "\nPlease supply at leat one valid input file path" << std::endl;
		return 0;
	}
	
	// For each file given as an argument
	for (int i = 1; i < argc; ++i)
	{
		CPU cpuProfile;
		InputOutput dataFile;
		Math math;
		
		dataFile.readFile(argv[i], cpuProfile);

		if (cpuProfile.getNumCores() > 0)
		{
			math.piecewiseLinearInterpolation(cpuProfile);
			math.linearLeastSquares(cpuProfile);
			dataFile.writeCPUData(cpuProfile, i);
		}
		else
		{
			std::cout << "\nNo data or unable to read file. Exiting." << std::endl;
		}
	}	
	return 0;
}