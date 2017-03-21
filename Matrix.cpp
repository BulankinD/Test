#include"Matrix.h"
#include<iostream>
#include <cstdlib>
#include <cstring>

using namespace Danil;

Matrix::Matrix(const Matrix & m) {
	this->raw_count = m.raw_count;
	this->col_count = m.col_count;
	this->values = new matrix_cell*[this->raw_count];
	for (size_t i = 0; i < this->raw_count; i++) {
		this->values[i] = new matrix_cell[this->col_count];
		for(size_t j = 0; j < this->col_count; j++)
			this->values[i][j] = m.values[i][j];
		/*std::memcpy(this->values[i], m.values[i], col_count);*/
	}
	count++;
}

Matrix::Matrix(int** mas, int raw, int col) {
	this->raw_count = raw;
	this->col_count = col;
	this->values = new matrix_cell*[this->raw_count];
	for (size_t i = 0; i < this->raw_count; i++) {
		this->values[i] = new matrix_cell[this->col_count];
		for(size_t j = 0; j < this->col_count; j++)
			this->values[i][j] = mas[i][j];
		/*std::memcpy(this->values[i], mas[i], col);*/
	}
	count++;
}

Matrix::Matrix(size_t raw_count , size_t col_count):
	raw_count(raw_count), col_count(col_count) {
	this->values = new matrix_cell*[this->raw_count];
	for (size_t i = 0; i < this->raw_count; i++) {
		this->values[i] = new matrix_cell[this->col_count];
	}
	count++;
}



Matrix::~Matrix() {
	for (size_t i = 0; i < this->raw_count; i++)
		delete []this->values[i];
	delete []this->values;
	count--;
}

matrix_cell Matrix::get(size_t i, size_t j) const {
	return this->values[i][j];
}

void Matrix::set(size_t i, size_t j, matrix_cell a) {
	this->values[i][j] = a;
}

Matrix Matrix::operator+(const Matrix &that) {
    if (this->raw_count == that.raw_count && this->col_count == that.col_count) {
        Matrix ans(this->raw_count, this->col_count);
        for (size_t i = 0; i < this->raw_count; i++) {
            for (size_t j = 0; j < this->col_count; j++) {
                ans.values[i][j] = this->values[i][j] + that.values[i][j];
            }
        }
        return ans;
    } else {
        cout << "Impossible" << endl;
        return that;
    }
}
Matrix Matrix::operator*(const Matrix &that) {
    if (this->col_count == that.raw_count) {
        Matrix ans(this->raw_count, that.col_count);
        for (size_t i = 0; i < ans.raw_count; i++) {
            for (size_t j = 0; j < ans.col_count; j++) {
                ans.values[i][j] = 0;
                for (size_t k = 0; k < this->col_count; k++) {
                    ans.values[i][j] += this->values[i][k] * that.values[k][j];
                }
            }
        }
        return ans;
    } else {
        cout << "Impossible" << endl;
        return that;
    }
}
Matrix Matrix::operator*(const int k) {
    Matrix ans(this->raw_count, this->col_count);
    for (size_t i = 0; i < this->raw_count; i++) {
        for (size_t j = 0; j < this->col_count; j++) {
            ans.values[i][j] = this->values[i][j] * k;
        }
    }
    return ans;
}

namespace Danil {
	std::istream& operator >>(std::istream& in, const Matrix& m) {
		for (size_t i = 0; i < m.raw_count; i++)
			for (size_t j = 0; j < m.col_count; j++)
				in >> m.values[i][j];
		return in;
	}

	std::ostream& operator <<(std::ostream& on, const Matrix& m) {
		for (size_t i = 0; i < m.raw_count; i++) {
			for (size_t j = 0; j < m.col_count; j++)
				on << m.values[i][j] << " ";
			on << "\n";
		}
		return on;
	}
	Matrix operator*(const int k, const Matrix &a) {
        Matrix ans(a.raw_count, a.col_count);
        for (size_t i = 0; i < a.raw_count; i++) {
            for (size_t j = 0; j < a.col_count; j++) {
                ans.values[i][j] = a.values[i][j] * k;
            }
        }
        return ans;
    }
}

int Matrix::count = 0;