#pragma once
#include <iostream>
#include "Matrix.h"
#define learning_rate 0.001


class Perceptron {
private:
	Matrix weights;
	Matrix bias;
	Matrix input;
	Matrix output;
public:
	Perceptron();
	Perceptron(Matrix w, Matrix b, Matrix i);
	Matrix feedforward();
	void update(Matrix target);
	void printOutput();
	void initializeWeightsRandomly(int numRows, int numCols, Matrix& weights);

};
