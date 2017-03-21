
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
	vector* mas = new vector[m];
    for (int i = 0; i < m; i++){
		mas[i].n = n;
		for (int j = 0; j < n; j++){
			int cin >> k;
			vector mas[i].set(i, k);
		}
    }
	int i, j;
	float c;
    cin >> i >> j;
	cin >> c;
    (mas[i]).printvec;
	(mas[i] + mas[j]).printvec;
    (mas[i] - mas[j]).printvec;
    cout << mas[i] * mas[j] << endl;
    cout << modul(mas[i]) << endl;
	cout << modul(mas[j]) << endl;
    (a ^ b).printvec;
    (a * c).printvec;
    return 0;
}