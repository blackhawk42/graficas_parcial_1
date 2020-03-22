#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	private:
		int rows, cols;
		double **mat;

	public:
		Matrix(int rows, int cols);
		~Matrix();

		int getRows();
		int getCols();

		double getValue(int row, int col);
		void setValue(int row, int col, double val);

		Matrix *multiply(Matrix *other);
};

#endif // MATRIX_H
