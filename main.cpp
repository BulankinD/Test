#include <iostream>
#include "Matrix.h"

using namespace Danil;
using namespace std;

int main() {
	int kk = 1;
	int** mas = new int*[2];
	for(int i = 0; i < 2; i++) {
		mas[i] = new int[];
		for (int j = 0; j < 2; j++)
			mas[i][j] = i + j;
	}
	Matrix a(mas, 2, 2);
    Matrix b(a);
    cout << b << endl;
    cout << a << endl;
    a.set(1, 1, 6);
    cout << a << endl;
    cout << a.get(1, 1) << endl;
    cout << a + b << endl;
    cout << a * b << endl;
    cout << a * 2 << endl;
    cout << 3 * a << endl;
	cout << Matrix::count << endl;
    return 0;
}
