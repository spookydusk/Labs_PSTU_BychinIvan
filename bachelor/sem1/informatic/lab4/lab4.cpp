#include <iostream>
#include <stdlib.h>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int initialSize = 10;
	const int maxSize = 20;
	int a[maxSize];
	int n = initialSize;
	cout << "Первоначальный массив: ";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
		{
			for (int j = i; j < n - 1; ++j)
			{
				a[j] = a[j + 1];
			}
			--n;
			i = n;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = n; j > i + 1; --j)
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = a[i] + 2;
			++n;
			++i;
		}
	}
	cout << "Массив после обработки: ";

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}