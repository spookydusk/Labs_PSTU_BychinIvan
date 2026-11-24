#include <iostream>
#include <cstdarg>
#include <clocale>
using namespace std;

float mult(int k, ...)
{
    va_list args;
    va_start(args, k);

    float result = 1;

    for (int i = 0; i < k; i++)
    {
        result *= va_arg(args, double);
    }

    va_end(args);

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Произведение 3 чисел: "
        << mult(3, 2.0f, 3.0f, 4.0f) << endl;

    cout << "Произведение 7 чисел: "
        << mult(7, 2.0f, 1.0f, 3.0f, 1.0f,
            2.0f, 1.0f, 1.0f) << endl;

    cout << "Произведение 11 чисел: "
        << mult(11, 1.0f, 2.0f, 1.0f, 3.0f,
            1.0f, 2.0f, 1.0f, 1.0f,
            2.0f, 1.0f, 1.0f) << endl;

    return 0;
}