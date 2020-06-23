#ifndef CS417_MATH_H_
#define CS417_MATH_H_

#include <vector>
#include "cpu.h"
#include "inputOutput.h"

namespace CS417_SP
{
	class Math
	{
	public:
		Math();
		~Math();

		void piecewiseLinearInterpolation(CPU &matrix);
		void linearLeastSquares(CPU &cpuProfile);
	private:

	};
}
#endif // !CS417_MATH_H_
