#include <iostream>
#include <complex>
#include <clocale>
using namespace std;

double Summa(double a, double b)
{
	return a + b;
}

complex<double> Summa(complex<double> a, complex<double> b)
{
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	cout << "Введи два вещественных числа a и b: ";
	cin >> a >> b;

	double re1, im1, re2, im2;
	cout << "Введи действительную и мнимую части числа c: ";
	cin >> re1 >> im1;
	complex<double> c(re1, im1);
	
	cout << "Введи действительную и мнимую части числа d: ";
	cin >> re2 >> im2;
	complex<double> d(re2, im2);

	cout << "Сумма вещественных чисел a и b = " << Summa(a, b) << endl;
	cout << "Сумма комплексных чисел c и d = " << Summa(c, d) << endl;

	return 0;
}