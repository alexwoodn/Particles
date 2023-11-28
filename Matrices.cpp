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
		return Matrix(0, 0); 
	}
	///Matrix comparison.  See description.
	///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b)
	{
		return false; 
	}

	///Matrix comparison.  See description.
	///usage:  a != b
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return false; 
	}

	///Output matrix.
	///Separate columns by ' ' and rows by '\n'
	ostream& operator<<(ostream& os, const Matrix& a)
	{
		return os; 
	}

}