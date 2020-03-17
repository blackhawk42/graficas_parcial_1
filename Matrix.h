#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	private:
		int rows, cols;
		int **mat;
	
	public:
		Matrix(int rows, int cols);
		~Matrix();

		int getRows();
		int getCols();

		int getValue(int row, int col);
		void setValue(int row, int col, int val);

		Matrix *multiply(Matrix *other);
};

#endif // MATRIX_H