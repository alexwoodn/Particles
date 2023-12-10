#include "Matrices.h"
namespace Matrices
{

	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows; 
		cols = _cols; 


		/*a.resize(rows);
		for (size_t i = 0; i < rows; i++)
		{
			a.at(i).resize(cols, 0);
			//for (size_t j = 0; j < cols; j++)
			//{
			//	a.at(i).at(j) = 0; 
			//}
			a.at(i).resize(cols, 0);
		}*/
		a.resize(rows, vector<double>(cols, 0));
	}

	///Add each corresponding element.
	///usage:  c = a + b;
	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		//if we get here, then the dimensions must match
		Matrix c(a.getRows(), b.getCols());
		//loop through each cell, assign each sum to cij

		for (int i = 0; i < a.getRows(); i++)
		{
			for(int j = 0; j < a.getCols(); j++)
			{
				c(i, j) = a(i, j) + b(i, j);
			}
		}




		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		int aRows = a.getRows();
		int aCols = a.getCols();
		int bRows = b.getRows();
		int bCols = b.getCols();

		// Check if multiplication is possible
		if (aCols != bRows) 
		{
			throw runtime_error("Error: dimensions must agree");
		}

		Matrix result(aRows, bCols);

		for (int i = 0; i < aRows; i++) {
			for (int j = 0; j < bCols; j++) {
				double sum = 0.0;
				for (int k = 0; k < aCols; k++) {
					sum += a(i, k) * b(k, j);
				}
				result(i, j) = sum;
			}
		}

		return result;
	}
	///Matrix comparison.  See description.
	///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
			return false;
		}

		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				if (abs(a(i, j) - b(i, j)) >= 0.001) {
					return false;
				}
			}
		}

		return true; // Matrices are equal
	}

	///Matrix comparison.  See description.
	///usage:  a != b
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return !(a == b);
	}


	///Output matrix.
	///Separate columns by ' ' and rows by '\n'
	ostream& operator<<(ostream& os, const Matrix& a)
	{
		int rows = a.getRows();
		int cols = a.getCols();

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				os << setw(8) << a(i, j);
				if (j < cols - 1) {
					os << ' ';
				}
			}
			os << '\n';
		}
		return os; 
	}



RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2) {
    this->operator()(0, 0) = cos(theta);
    this->operator()(0, 1) = -sin(theta);
    this->operator()(1, 0) = sin(theta);
    this->operator()(1, 1) = cos(theta);
}
ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2) {
    this->operator()(0, 0) = scale;
    this->operator()(0, 1) = 0;
    this->operator()(1, 0) = 0;
    this->operator()(1, 1) = scale;
}
TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols) {
    for (int col = 0; col < nCols; ++col) {
        this->operator()(0, col) = xShift;
        this->operator()(1, col) = yShift;
    }
}
}
