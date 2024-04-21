#include "Matrix.h"
#include <iostream>
#include <vector>

Matrix::Matrix() : rows(3), columns(3) {};
Matrix::Matrix(int rowsInput, int colsInput) : rows(rowsInput), columns(colsInput) {
	data.resize(rows, std::vector<double>(columns, 0));
}
int Matrix::getRowCount() {
	return rows;
}
int Matrix::getColCount() {
	return columns;
}
void Matrix::setMatVal(int r, int c, double val) {
	data[r][c] = val;
}
double Matrix::getMatVal(int r, int c) {
	return data[r][c];
}
void Matrix::printMatrix() {
	std::cout << "Matrix: \n";
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
};
void Matrix::printMatrix(Matrix& uno) {
	std::cout << "Matrix: \n";
	for (int i = 0; i < uno.getColCount(); i++) {
		for (int j = 0; j < uno.getRowCount(); j++) {
			std::cout << uno.getMatVal(i,j) << " ";
		}
		std::cout << std::endl;
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

//Matrix Subtraction
const Matrix operator -(Matrix& uno, Matrix& dos) {
	if ((uno.getColCount() != dos.getColCount()) || (uno.getRowCount() != dos.getRowCount())) {
		std::cout << "Cannot subtract matrices with different orders! \n";
	}

	Matrix outputMat(uno.getRowCount(), uno.getColCount());

	for (int g = 0; g < uno.getRowCount(); g++) {
		for (int h = 0; h < uno.getColCount(); h++) {
			//outputMat.data[g][h] = (uno.data[g][h]) + (dos.data[g][h]);
			outputMat.setMatVal(g, h, (uno.getMatVal(g, h) - dos.getMatVal(g, h)));
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

Matrix sigmoid(Matrix& input) {
	Matrix output(input.getRowCount(), input.getColCount());
	for (int i = 0; i < input.getRowCount(); ++i) {
		for (int j = 0; j < input.getColCount(); ++j) {
			// Calculate sigmoid using element-wise operation
			double val = input.getMatVal(i, j);
			output.setMatVal(i, j, 1.0 / (1.0 + exp(-val)));
		}
	}
	return output;
}