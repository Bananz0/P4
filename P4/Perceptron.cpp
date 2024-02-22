#include "Perceptron.h"

Perceptron::Perceptron()
{
	weights = Matrix(2, 2);
	bias = Matrix(2, 2);
}
Perceptron::Perceptron(Matrix w, Matrix b, Matrix i)
{
	weights = w;
	bias = b;
	input = i;
}

Matrix Perceptron::feedforward()
{
	output_nb = (weights * input);
	output = output_nb + bias;
	return output;
}

void Perceptron::update(/*YOUR INPUT*/)
{
	// YOUR CODE HERE
}

//Include any functions which may be useful to you (e.g. print functions)