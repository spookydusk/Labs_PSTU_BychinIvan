#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double pi = acos(-1.0);
    const double a = pi / 5.0;     // начало диапазона
    const double b = 9.0 * pi / 5.0; // конец диапазона
    const double eps = 0.0001;     // заданная точность
    const int k = 10;              // число промежутков по x
    const int n = 40;              // число слагаемых для суммы Sn
    const double h = (b - a) / k;  // шаг x

    cout << fixed << setprecision(6); // формат вывода

    for (int i = 0; i <= k; ++i)
    {
        const double x = a + i * h; //изменение x от a до b с шагом h
        double SN = 0.0;            // сумма ряда для n = 40
        for (int m = 1; m <= n; ++m)
        {
            SN += cos(m * x) / m;
        }

        double SE = 0.0;            // сумма ряда с точностью eps
        int m = 1;                  // номер текущего слагаемого
        double term = cos(m * x) / m;

        while (abs(term) >= eps)
        {
            SE += term;
            ++m;
            term = cos(m * x) / m;
        }

        const double Y = -log(abs(2.0 * sin(x / 2.0)));

        cout << "X=" << x
            << " SN=" << SN
            << " SE=" << SE
            << " Y=" << Y << endl;
    }

    return 0;
}