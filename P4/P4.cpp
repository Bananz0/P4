#include <iostream>
#include "vector"
	
class Matrix {	
private:
	int rows, columns;
	std::vector<std::vector<double>> data;
	public:	
	Matrix() : rows(10), columns(10) {};
	Matrix(int rowsInput, int colsInput): rows(rowsInput) , columns(colsInput) {		
		data.resize(rows, std::vector<double>(columns, 0));
	}
	int getRowCount() {
		return rows;
	}
	int getColCount() {
		return columns;
	}
	void setMatVal(int r, int c, double val) {
		data[r][c] = val;
	}
	double getMatVal(int r, int c) {
		return data[r][c];
	}
	void printMatrix() {
		std::cout << "Matrix: \n";
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				std::cout << data[i][j] << " ";
			}
			std::cout << std::endl;
		}
		
	}
};

//Matrix Addition
const Matrix operator +(Matrix& uno, Matrix& dos) {
	if ((uno.getColCount() != dos.getColCount()) || (uno.getRowCount() != dos.getRowCount())) {
		std::cout << "Cannot add matrices with different orders! \n";
	}

	Matrix outputMat(uno.getRowCount(), uno.getColCount());

	for (int g = 0; g < uno.getRowCount(); g++) {
		for (int h = 0; h < uno.getColCount(); h++) {
			//outputMat.data[g][h] = (uno.data[g][h]) + (dos.data[g][h]);
			outputMat.setMatVal(g, h, (uno.getMatVal(g, h) + dos.getMatVal(g, h)));
		}
	}
	return outputMat;
}

//Matrix Multiplication
const Matrix operator *(Matrix& uno, Matrix& dos) {
	if ((uno.getColCount() != dos.getColCount()) || (uno.getRowCount() != dos.getRowCount())) {
		std::cout << "Cannot multiply matrices with different rows and columns! \n";
		return Matrix();
	}

	Matrix outputMat(uno.getRowCount(), dos.getColCount());
	
	
	for (int i = 0; i < outputMat.getRowCount(); ++i) {
		for (int j = 0; j < outputMat.getColCount(); ++j) {
			double sum = 0;
			for (int k = 0; k < uno.getColCount(); ++k) {
				sum += uno.getMatVal(i, k) * dos.getMatVal(k, j);
			}
			outputMat.setMatVal(i, j, sum);
		}
	}
	return outputMat;
}

int main()
{
	Matrix glenm(5,5);
	Matrix glenm2(5, 5);
	glenm.setMatVal(3, 4, 5);
	glenm2.setMatVal(1, 4, 5);
	Matrix glenm3 = glenm + glenm2;
	glenm3.printMatrix();
}