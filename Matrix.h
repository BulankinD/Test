#include<cstdlib>
#include<iostream>

typedef int matrix_cell;

using namespace std;

namespace Danil {
	class Matrix {
	private:
		size_t raw_count;
		size_t col_count;
		matrix_cell** values;
		

	public:
		Matrix(const Matrix &);
		Matrix(size_t, size_t);
		Matrix(int**, int, int);
		~Matrix();		
		

		matrix_cell get(size_t, size_t) const;
		void set(size_t , size_t , matrix_cell);
		friend istream& operator>>(istream&, const Matrix&);
		friend ostream& operator<<(ostream&, const Matrix&);
		friend Matrix operator*(const int , const Matrix &);
        Matrix operator+(const Matrix &);
        Matrix operator*(const Matrix &);
        Matrix operator*(const int );
		static Matrix eye(size_t);
		static int count;
	};
}
