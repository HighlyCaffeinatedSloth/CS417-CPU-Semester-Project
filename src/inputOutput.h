#ifndef CS417_IO_H_
#define CS417_IO_H_

#include <vector>
#include "cpu.h"

namespace CS417_SP
{
	class InputOutput
	{
	public:
		/**
		 * @brief Function reads a given input file and parses its content:
		 * 
		 * 1. Sanitizes data by calling removeCharsNotInLanguage()
		 * 2. Logs all tempertaure data for each core at each interval
		 * 3. Sets the number of cores and intervals on the CPU object for later calcualtions
		 * 
		 * @param infile: in-file name
		 * @param matrix: CPU object
		 */
		void readFile(const char* infile, CPU &matrix);

		/**
		 * @brief Creates an output txt file for computed data
		 * 
		 * @param data: Computed CPU object data 
		 * @param file: out-file index indicating the arg source data
		 */
		void writeCPUData(CPU &data, int file);

	private:
		const std::string alphabet = "0123456789. ";

		/**
		 * @brief Sanitizes an input string removing all characters not in language
		 * 
		 * @param str: String to be sanitized
		 * @param language: acceptable chars in language
		 */
		std::string& removeCharsNotInLanguage(std::string& str, const std::string& language);
	};
}
#endif // !CS417_IO_H_


