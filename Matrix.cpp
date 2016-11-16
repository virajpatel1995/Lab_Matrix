#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	//Allocate a tow dimensional array
	array = new double*[rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new double[cols];
	}
}

Matrix::Matrix(const Matrix& m) {
	rows = m.numRows();
	cols = m.numCols();

	//Allocate a tow dimensional array
	array = new double*[rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new double[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			array[i][j] = m.at(i, j);
		}
	}	
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] array[i];
	}
	delete[] array;
}

Matrix Matrix::add(double s) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//add an element
			newMatrix.at(i, j) = array[i][j] + s;
		}
	}
	return newMatrix;
}

Matrix Matrix::add(const Matrix& m) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix.at(i, j) = array[i][j] + m.at(i, j);
		}
	}
	return newMatrix;
}

Matrix Matrix::subtract(double s) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {			
			newMatrix.at(i, j) = array[i][j] - s;
		}
	}
	return newMatrix;
}

Matrix Matrix::subtract(const Matrix& m) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix.at(i, j) = array[i][j] - m.at(i, j);
		}
	}
	return newMatrix;
}

Matrix Matrix::multiply(double s) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {			
			newMatrix.at(i, j) = array[i][j] * s;
		}
	}
	return newMatrix;
}

Matrix Matrix::multiply(const Matrix& m) {	
	Matrix newMatrix(rows, m.numCols());
	//multiply	
	int i = 0;
	while (i != rows)
	{
		for (int j = 0; j != m.numCols(); j++)
		{
			int sum = 0;
			for (int k = 0; k != cols; k++)
			{
				sum += array[i][k] * m.at(k, j);
			}
			newMatrix.at(i, j) = sum;
		}
		i++;
	}
	return newMatrix;
}

Matrix Matrix::divide(double s) {
	Matrix newMatrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newMatrix.at(i, j) = array[i][j] / s;
		}
	}
	return newMatrix;
}

const int Matrix::numRows() const{
	return rows;
}

const int Matrix::numCols() const{
	return cols;
}

double& Matrix::at(int row, int col) {
	return array[row][col];
}

const double& Matrix::at(int row, int col) const{
	return array[row][col];
}

Matrix Matrix::t() const{
	Matrix newMatrix(cols, rows);
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			newMatrix.at(j, i) = array[i][j];
		}
	}
	return newMatrix;
}

void Matrix::print() {	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void operator<<(Matrix& m, initList list) {

	int rows = list.size();
	int cols = list.begin()->size();

	int k = 0, l = 0;

	for (auto i = list.begin(); i != list.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			m.at(k,l) = *j;
			l++;
		}
		k++;
		l = 0;
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix m) {
	for (int i = 0; i < m.numRows(); i++) {
		for (int j = 0; j < m.numCols(); j++) {
			out << m.at(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}

Matrix operator+(Matrix m1, const Matrix m2) {
	Matrix newMatrix = m1.add(m2);
	return newMatrix;
}

Matrix operator+(Matrix m1, double s) {
	return m1.add(s);
}

Matrix operator-(Matrix m1, const Matrix m2) {
	Matrix newMatrix = m1.subtract(m2);
	return newMatrix;
}

Matrix operator-(Matrix m1, double s) {
	return m1.subtract(s);
}

Matrix operator*(Matrix m1, const Matrix m2) {
	Matrix newMatrix = m1.multiply(m2);
	return newMatrix;
}

Matrix operator*(Matrix m1, double s) {
	return m1.multiply(s);
}

Matrix operator/(Matrix m1, double s) {
	return m1.divide(s);
}