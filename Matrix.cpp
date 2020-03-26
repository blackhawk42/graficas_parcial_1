#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	this->mat = new double*[rows];
	for(int i = 0; i < rows; i++) {
		this->mat[i] = new double[cols];
	}
}

Matrix::~Matrix() {
	for(int i = 0; i < this->rows; i++) {
		delete[] this->mat[i];
	}

	delete[] this->mat;
}

int Matrix::getRows() {
	return this->rows;
}

int Matrix::getCols() {
	return this->cols;
}

double Matrix::getValue(int row, int col) {
	if(row < 0 || col < 0) {
		throw 1;
	}

	if(row > this->rows || col > this->cols) {
		throw 2;
	}

	return this->mat[row][col];
}

void Matrix::setValue(int row, int col, double val) {
	if(row < 0 || col < 0) {
		throw 1;
	}

	if(row >= this->rows || col >= this->cols) {
		throw 2;
	}

	this->mat[row][col] = val;
}

Matrix *Matrix::multiply(Matrix *other) {
	if(this->cols != other->rows) {
		throw 3;
	}

	Matrix *result = new Matrix(this->rows, other->cols);

	double dot_product;
	for(int i = 0; i < this->rows; i++) {
		for(int j = 0; j < other->cols; j++) {
			dot_product = 0;

			for(int k = 0; k < this->cols; k++) {
				dot_product += this->mat[i][k]*other->mat[k][j];
			}

			result->mat[i][j] = dot_product;
		}
	}

	return result;
}

