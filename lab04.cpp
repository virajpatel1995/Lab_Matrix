#include "Matrix.h"

int main() {	

	//Input matrix m1
	Matrix m1(3,2);
	m1.at(0, 0) = 1;
	m1.at(0, 1) = 21;
	m1.at(1, 0) = 67.3;
	m1.at(1, 1) = 0.23;
	m1.at(2, 0) = 15;
	m1.at(2, 1) = 10.5;

	//m1 << {{1,21}, {67.3,0.23}, {15,10.5}}; //does not work,

	std::cout << "Matrix m1: \n" << m1 << std::endl;
	std::cout << "Matrix m1 multiplied by 5: \n" << m1.multiply(5) << std::endl;
	std::cout << "Transposed matrix m1: \n" << m1.t() << std::endl;

	//Input matrix m2
	Matrix m2(3, 2);
	m2.at(0, 0) = 54;
	m2.at(0, 1) = 2;
	m2.at(1, 0) = 7.3;
	m2.at(1, 1) = 6.23;
	m2.at(2, 0) = 32;
	m2.at(2, 1) = 5;

	std::cout << "Matrix m2: \n" << m2 << std::endl;
	//test addition
	std::cout << "m1 + m2: \n" << m1 + m2 << std::endl;
	std::cout << "m1 + 5: \n" << m1 + 5 << std::endl;
	//test substruction
	std::cout << "m1 - m2: \n" << m1 - m2 << std::endl;
	std::cout << "m1 - 5: \n" << m1 - 5 << std::endl;	

	//test multiplication
	std::cout << "m2 transposed: \n" << m2.t() << std::endl;
	std::cout << "m1 * m2 transposed: \n" << m1 * m2.t() << std::endl;
	std::cout << "m1 * 5: \n" << m1 * 5 << std::endl;

	//test division
	std::cout << "m1 / 5: \n" << m1 / 5 << std::endl;

	return 0;
}