#include <iostream>
#include <vector>
#include <iostream>
#include "Matrix.h"
#include "Perceptron.h"



int main()
{
	Matrix weight(2, 2);
	Matrix bias(2, 2);
	Matrix input(2 ,2);
	Matrix target(2, 2);
	
	weight.setMatVal(0, 0, 0.75);
	weight.setMatVal(0, 1, 1.8);
	weight.setMatVal(1, 0, 1.24);
	weight.setMatVal(1, 1, 0.6);

	bias.setMatVal(0, 0, 0);
	bias.setMatVal(0, 1, 0);
	bias.setMatVal(1, 0, 0);
	bias.setMatVal(1, 1, 0);

	input.setMatVal(0, 0, 1.1);
	input.setMatVal(0, 1, 1.3);
	input.setMatVal(1, 0, 1.7);
	input.setMatVal(1, 1, 0.9);
	
	target.setMatVal(0, 0, 0);
	target.setMatVal(0, 1, 1);
	target.setMatVal(1, 0, 0);
	target.setMatVal(1, 1, 1);

	

	Perceptron glena(weight, bias, input);

	std::cout << "Output before update:\n";
	glena.feedforward();
	glena.printOutput();


	for (int i = 0; i < 100; i++) {
		// Update and print output again
		glena.update(target);
		std::cout << "Output after update:\n";
		glena.feedforward();
		glena.printOutput();
		
	}
	

}