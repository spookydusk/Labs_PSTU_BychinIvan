#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	float aF = 1000.0f;
	float bF = 0.0001f;
	float resF = ((aF - bF) * (aF - bF) - (aF * aF - 2 * aF * bF)) / (bF * bF);

	double aD = 1000.0;
	double bD = 0.0001;
	double resD = ((aD - bD) * (aD - bD) - (aD * aD - 2 * aD * bD)) / (bD * bD);

	cout << "float:  " << resF << '\n';
	cout << "double: " << resD << '\n';

	int m0, n0;
	cout << "Введите начальные значения m и n: ";
	cin >> m0 >> n0;

	int m = m0, n = n0;
	int res1 = ++n * ++m;
	cout << "1) ++n * ++m = " << res1
		<< ", m = " << m << ", n = " << n << '\n';

	m = m0;
	n = n0;
	bool res2 = m++ < n;
	cout << "2) m++ < n = " << res2
		<< ", m = " << m << ", n = " << n << '\n';

	m = m0;
	n = n0;
	bool res3 = n++ > m;
	cout << "3) n++ > m = " << res3
		<< ", m = " << m << ", n = " << n << '\n';
	return 0;
}