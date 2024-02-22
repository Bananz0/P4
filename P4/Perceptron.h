#pragma once
#include <iostream>
#include "Matrix.h"

class Perceptron {
private:
	Matrix weights;
	Matrix bias;
	Matrix input;
	Matrix output;
	Matrix output_nb;
public:
	Perceptron();
	Perceptron(Matrix w, Matrix b, Matrix i);
	Matrix feedforward();
	void update(/*YOUR INPUT*/);

};
