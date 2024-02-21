#include <iostream>
#include "vector"
	
class Matrix {
private:
	size_t rows, columns;
	std::vector<std::vector<double>> data;
public:	
	int glenm;
	Matrix(int rowsInput, int colsInput): rows(rowsInput) , columns(colsInput) {		
		data.resize(rows, std::vector<double>(columns, 0));
	}
};

int main()
{
	
}