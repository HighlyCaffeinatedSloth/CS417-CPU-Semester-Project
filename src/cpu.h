#ifndef CS417_CPU_H_
#define CS417_CPU_H_

#include <vector>
#include <math.h>
#include <Dense>

namespace CS417_SP
{
	class CPU
	{
	private:
		const int intervalTime = 30;
		int intervals;
		int cores;
		
		std::vector< std::vector<double> > m_leastSquaresData;
		std::vector< std::vector<double> > m_linearInterpData;
		std::vector< std::vector<double> > m_Temperatures;
	public:
		CPU();

		~CPU();
		/**
		 * @brief Get the Num Intervals object
		 * 
		 * @return int 
		 */
		inline int getNumIntervals() { return intervals; }

		/**
		 * @brief Get the Interval Time object
		 * 
		 * @return int 
		 */
		inline int getIntervalTime() { return intervalTime; }

		/**
		 * @brief Get the Num Linear Interp Rows object
		 * 
		 * @return int 
		 */
		inline int getNumLinearInterpRows() { return m_linearInterpData.size(); }

		/**
		 * @brief Get the Num Cores object
		 * 
		 * @return int 
		 */
		inline int getNumCores() { return cores; }

		/**
		 * @brief Get the Liner Interp Data At object
		 * 
		 * @param row 
		 * @param col 
		 * @return double 
		 */
		inline double getLinerInterpDataAt(int row, int col) { return m_linearInterpData[row][col]; }

		/**
		 * @brief 
		 * 
		 * @param row 
		 * @param col 
		 * @return double 
		 */
		inline double getLLSQDataAt(int row, int col) { return m_leastSquaresData[row][col]; }

		/**
		 * @brief Get the Core Temperature At Interval object
		 * 
		 * @param interval 
		 * @param core 
		 * @return double 
		 */
		double getCoreTemperatureAtInterval(int interval, int core);

		/**
		 * @brief Set the Num Cores object
		 * 
		 */
		inline void setNumCores() { cores = m_Temperatures[0].size(); }

		/**
		 * @brief Set the Num Intervals object
		 * 
		 * @param i 
		 */
		inline void setNumIntervals(int i) { intervals = i; }

		/**
		 * @brief 
		 * 
		 * @param x0 
		 * @param x1 
		 * @param y1 
		 * @param m 
		 */
		void logLLSQData(double &x0, double &x1, double &y1, double &m);

		/**
		 * @brief 
		 * 
		 * @param x0 
		 * @param x1 
		 * @param y1 
		 * @param m 
		 */
		void logLinearInterpData(double &x0, double &x1, double &y1, double &m);

		/**
		 * @brief 
		 * 
		 * @param temps 
		 */
		void logTemperatureReading(std::vector<double> temps);
	};
}
#endif // !CS417_CPU_H_

