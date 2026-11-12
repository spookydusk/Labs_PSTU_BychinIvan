#include <iostream>
#include <clocale>

using namespace std;

const int Rows = 100;
const int Cols = 3;

void swapRows(int arr[][Cols], int row1, int row2)
{
    for (int j = 0; j < Cols; j++)
    {
        int temp = arr[row1][j];
        arr[row1][j] = arr[row2][j];
        arr[row2][j] = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int rows;

    cout << "Введи количество строк от 2 до 100: ";
    cin >> rows;

    if (rows < 1)
    {
        cout << "Некорректное количество строк.";
        return 0;
    }

    if (rows > Rows)
    {
        cout << "Максимальное количество строк: 100.";
        return 0;
    }

    int arr[Rows][Cols];

    cout << "Заполни массив: ";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < rows; j++)
        {
            if (arr[j][2] < arr[min_index][2])
            {
                min_index = j;
            }
        }

        swapRows(arr, i, min_index);
    }

    cout << "Отсортированный массив:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}