#include <vector>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

#include <filesystem>

#include "inputOutput.h"
#include "math.h"
#include "cpu.h"

namespace fs = std::filesystem;

void CS417_SP::InputOutput::readFile(const char* infile, CPU &cpuProfile)
{
	std::ifstream fin(infile);
	std::string line;
	std::vector<double> m_CoreTemps;
	int intervals = 0;
	
	if (fs::exists(infile))
	{	
		while (std::getline(fin, line))
		{
			//Cleanup line
			std::stringstream cleanLine(removeCharsNotInLanguage(line, alphabet));
			
			//
			double temperatureFromString;
			std::vector<double> tempsAtInterval;
			while (cleanLine >> temperatureFromString) 
			{
				tempsAtInterval.push_back(temperatureFromString);
				
			}
			cpuProfile.logTemperatureReading(tempsAtInterval);
			intervals++;
		}
		// Set 
		cpuProfile.setNumIntervals(intervals);
		cpuProfile.setNumCores();	
	}
	else
	{
		std::cout << "Cannot read " << infile << "\n";
	}
}

void CS417_SP::InputOutput::writeCPUData(CPU & data, int file)
{
	int core = 0;
	int cores = data.getNumCores();
	int rowsPerCore = data.getNumLinearInterpRows() / cores;
	int row = 0;

	time_t seconds;
	std::string dt = std::to_string(time(&seconds));

	// For each core create the datafile and populate it
	for (int coreRow = 0; coreRow < cores; ++coreRow)
	{
		std::string name = dt + "-Temperature-Data-" + std::to_string(file) + "-Core-" + std::to_string(core) + ".txt";
		while (fs::exists(name))
		{
			core++;
			std::string name = dt + "-Temperature-Data-" + std::to_string(file) + "-Core-" + std::to_string(core) + ".txt";
		}
		
		std::ofstream outfile(name);
		for (int i = 0; i < rowsPerCore; ++i, ++row)
		{
			outfile <<
				std::setprecision(1) <<
				std::fixed <<
				std::noshowpos <<
				data.getLinerInterpDataAt(row, 0) << " <= x < " <<
				data.getLinerInterpDataAt(row, 1) << "; y = " <<
				data.getLinerInterpDataAt(row, 2) << " ";

			outfile <<
				std::setprecision(8) <<
				std::fixed <<
				std::showpos <<
				data.getLinerInterpDataAt(row, 3) << "x" << "; Piecewise Linear Interpolation" << std::endl;
		}

		outfile <<
			std::setprecision(1) <<
			std::fixed <<
			std::noshowpos <<
			data.getLLSQDataAt(core, 0) << " <= x < " <<
			data.getLLSQDataAt(core, 1) << "; y = " <<
			data.getLLSQDataAt(core, 2) << " ";

		outfile <<
			std::setprecision(8) <<
			std::fixed <<
			std::showpos <<
			data.getLLSQDataAt(core, 3) << "x" << "; Global Linear Least Squares" << std::endl;

		outfile.close();
		core++;		
	}
}

std::string &CS417_SP::InputOutput::removeCharsNotInLanguage(std::string &str, const std::string &language)
{
	str.erase(std::remove_if(str.begin(), str.end(), [&language](const char& c)
	{return language.find(c) == std::string::npos;}), str.end());
	return str;
}
