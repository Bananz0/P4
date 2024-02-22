#include <iostream>
#include <vector>
#include <iostream>
#include "Matrix.h"



int main()
{
	Matrix glenm(2, 2);
	Matrix glenm2(2, 2);

	glenm.setMatVal(0, 0, 4);
	glenm.setMatVal(0, 1, 3);
	glenm.setMatVal(1, 0, 3);
	glenm.setMatVal(1, 1, 2);

	glenm2.setMatVal(0, 0, -2);
	glenm2.setMatVal(0, 1, 3);
	glenm2.setMatVal(1, 0, 3);
	glenm2.setMatVal(1, 1, -4);

	Matrix glenm3 = glenm * glenm2;
	glenm3.printMatrix();
}