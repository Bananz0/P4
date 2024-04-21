#include "Perceptron.h"
#include <ctime>

Perceptron::Perceptron()
{
	weights = Matrix();
	bias = Matrix();
}
Perceptron::Perceptron(Matrix w, Matrix b, Matrix i)
{
	weights = w;
	bias = b;
	input = i;
    	
}

Matrix Perceptron::feedforward()
{
    Matrix output_nb = weights * input;
    output = output_nb + bias;

    //output = sigmoid(output); 

    for (int i = 0; i < output.getColCount(); i++) {
        if (output.getMatVal(0, i) > 0.0) {
            output.setMatVal(0, i, 1.0);
        }
        else {
            output.setMatVal(0, i, 0.0);
        }
    }

    return output;
}

void Perceptron::update(Matrix target) {
    // Do not edit this function unless you know what you are doing!
    // These are code pre-written for you to ensure the lab runs smoothly!

    for (int i = 0; i < target.getRowCount(); i++) {
        for (int j = 0; j < weights.getColCount(); j++) {
            double weight_update = learning_rate * (target.getMatVal(i, 0) - output.getMatVal(i, 0)) * input.getMatVal(j, 0);
            weights.setMatVal(i, j, weights.getMatVal(i, j) + weight_update);
        }
    }

    for (int i = 0; i < target.getRowCount(); i++) {
        double bias_update = learning_rate * (target.getMatVal(i, 0) - output.getMatVal(i, 0));
        bias.setMatVal(0, i, bias.getMatVal(0, i) + bias_update);
    }
}

void Perceptron::printOutput() {
	output.printMatrix();
}

void Perceptron::initializeWeightsRandomly(int numRows, int numCols, Matrix& weights) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize weights with random values between -1 and 1
     weights = Matrix(numRows, numCols);
     for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            double randValue = (double)rand() / RAND_MAX; // Generate random value between 0 and 1
            double scaledRandValue = 2 * randValue - 1;   // Scale to range [-1, 1]
            weights.setMatVal(i, j, scaledRandValue);
        }
    }
}