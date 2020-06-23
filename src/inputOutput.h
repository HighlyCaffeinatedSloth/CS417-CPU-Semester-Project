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
		 * @brief 
		 * 
		 * @param infile 
		 * @param matrix 
		 */
		void readFile(const char* infile, CPU &matrix);

		/**
		 * @brief 
		 * 
		 * @param data 
		 * @param file 
		 */
		void writeCPUData(CPU &data, int file);

	private:
		const std::string alphabet = "0123456789. ";

		/**
		 * @brief Sanitizes an input string removing all characters not in private: const alphabet
		 * 
		 * @param str 
		 * @param language raw string input
		 * @return language  sanitized string 
		 */
		std::string& removeCharsNotInLanguage(std::string& str, const std::string& language);
	};
}
#endif // !CS417_IO_H_


