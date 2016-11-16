#include <initializer_list>
#include <iostream>

typedef std::initializer_list<std::initializer_list<double>> initList;

class Matrix {

private:
	int rows;
	int cols;
	double** array;

	void print();

public:
	Matrix(int rows, int cols); // constructor (all elements initialized to 0)
	Matrix(const Matrix & m); // copy constructor
	~Matrix(); // destructor
	Matrix add(double s); // add scalar to this matrix
	Matrix add(const Matrix & m); // add this matrix and another matrix
	Matrix subtract(double s); // subtract scalar from this matrix
	Matrix subtract(const Matrix & m); // subtract another matrix from this matrix
	Matrix multiply(double s); // multiply this matrix by a scaler
	Matrix multiply(const Matrix & m); // multiply this matrix by another matrix
	Matrix divide(double s); // divide this matrix by a scaler
	Matrix t() const; // transpose of this matrix
	const int numRows() const; // returns the number of rows
	const int numCols() const; // returns the number of cols
	double & at(int row, int col); // get/set element at row,col
	const double & at(int row, int col) const; // get element at row,col (when using a const object)

	

}; // Matrix

void operator<<(Matrix& m, initList list);
std::ostream& operator<<(std::ostream& out, const Matrix m);
Matrix operator+(Matrix m1, const Matrix m2);
Matrix operator+(Matrix m1, double s);
Matrix operator-(Matrix m1, const Matrix m2);
Matrix operator-(Matrix m1, double s);
Matrix operator*(Matrix m1, const Matrix m2);
Matrix operator*(Matrix m1, double s);
Matrix operator/(Matrix m1, double s);


