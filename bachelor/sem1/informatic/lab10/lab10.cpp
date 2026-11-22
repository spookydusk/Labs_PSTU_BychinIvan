#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Неверный размер массива!";
        return 0;
    }

    int* a = new int[n];

    cout << "Введите элементы массива: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Исходный массив: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    int deleteKey, addKey;

    cout << "\nВведите значение для удаления: ";
    cin >> deleteKey;

    cout << "Введите значение для добавления: ";
    cin >> addKey;

    int position = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == deleteKey)
        {
            if(position == -1)
                position = i;
        }
    }

    if (position != -1)
    {
        for (int i = position; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }

        n--;

        cout << "Элемент удалён." << endl;
    }
    else
    {
        cout << "Элемент не найден." << endl;
    }

    int* newA = new int[n + 1];

    for (int i = 0; i < n; i++)
    {
        newA[i] = a[i];
    }

    newA[n] = addKey;

    delete[] a;

    a = newA;
    n++;

    cout << "Итоговый массив: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    delete[] a;

    return 0;
}