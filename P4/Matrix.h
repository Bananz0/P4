#pragma once
#include <iostream>
#include <vector>
 
class Matrix {
private:
	int rows, columns;
	
public:
	std::vector<std::vector<double>> data;

	Matrix();
	Matrix(int rowsInput, int colsInput);
	int getRowCount();
	int getColCount();
	Matrix setData(std::vector<std::vector<double>>& data);
	void setMatVal(int r, int c, double val);
	double getMatVal(int r, int c);
	void printMatrix();
	void printMatrix(Matrix& uno);
};

//Matrix Addition
const Matrix operator +(Matrix& uno, Matrix& dos);

//Matrix Multiplication
const Matrix operator *(Matrix& uno, Matrix& dos);

Matrix sigmoid(Matrix& input);

//Matrix Multiplication
const Matrix operator -(Matrix& uno, Matrix& dos);


