#pragma once
#include <iostream>
#include <vector>
 
class Matrix {
private:
	int rows, columns;
	std::vector<std::vector<double>> data;
public:
	Matrix();
	Matrix(int rowsInput, int colsInput);
	int getRowCount();
	int getColCount();
	void setMatVal(int r, int c, double val);
	double getMatVal(int r, int c);
	void printMatrix();
};

//Matrix Addition
const Matrix operator +(Matrix& uno, Matrix& dos);

//Matrix Multiplication
const Matrix operator *(Matrix& uno, Matrix& dos);

