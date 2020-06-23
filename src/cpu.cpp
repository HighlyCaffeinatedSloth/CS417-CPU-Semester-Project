#include "cpu.h"

CS417_SP::CPU::CPU()
{
}

CS417_SP::CPU::~CPU()
{
}

double CS417_SP::CPU::getCoreTemperatureAtInterval(int interval, int core)
{
	return m_Temperatures[interval][core];
}

void logTemperature(double temp, int interval)
{

}

void CS417_SP::CPU::logLLSQData(double & x0, double & x1, double & y1, double & m)
{
	m_leastSquaresData.push_back(std::vector<double>());
	int i = m_leastSquaresData.size() - 1;

	m_leastSquaresData[i].push_back(x0);
	m_leastSquaresData[i].push_back(x1);
	m_leastSquaresData[i].push_back(y1);
	m_leastSquaresData[i].push_back(m);
}

void CS417_SP::CPU::logLinearInterpData(double & x0, double & x1, double & y1, double & m)
{
	m_linearInterpData.push_back(std::vector<double>());
	int i = m_linearInterpData.size() - 1;

	m_linearInterpData[i].push_back(x0);
	m_linearInterpData[i].push_back(x1);
	m_linearInterpData[i].push_back(y1);
	m_linearInterpData[i].push_back(m);
}

void CS417_SP::CPU::logTemperatureReading(std::vector<double> temps)
{
	int interval = m_Temperatures.size();
	m_Temperatures.push_back(std::vector<double>());

	for (auto t : temps)
	{
		m_Temperatures[interval].push_back(t);
	}
}



