#include <iostream>
#include <clocale>
using namespace std;

const int N = 5; // Количество колец

int moveCount = 0;

// Массивы для хранения колец на трёх стержнях
int towers[3][N] = {};
int disksOnTower[3] = { N, 0, 0 };

// Вывод одного кольца или пустого места
void printDisk(int disk)
{
    int width = 2 * N + 1;
    int diskWidth = (disk == 0) ? 1 : 2 * disk + 1;
    int spaces = (width - diskWidth) / 2;

    for (int i = 0; i < spaces; i++)
        cout << " ";

    if (disk == 0)
        cout << "|";
    else
        for (int i = 0; i < diskWidth; i++)
            cout << "=";

    for (int i = 0; i < spaces; i++)
        cout << " ";
}

// Вывод текущего состояния всех стержней
void printTowers()
{
    cout << endl;

    for (int level = N - 1; level >= 0; level--)
    {
        for (int tower = 0; tower < 3; tower++)
        {
            int disk = 0;

            if (disksOnTower[tower] > level)
                disk = towers[tower][level];

            printDisk(disk);
        }

        cout << endl;
    }

    for (int tower = 0; tower < 3; tower++)
    {
        for (int i = 0; i < 2 * N + 1; i++)
            cout << "=";
    }

    cout << endl;
    cout << "      1           2           3" << endl;
}

// Перемещение верхнего кольца
void moveDisk(int from, int to)
{
    int disk = towers[from - 1][--disksOnTower[from - 1]];

    towers[to - 1][disksOnTower[to - 1]++] = disk;

    moveCount++;

    cout << endl;
    cout << "Ход " << moveCount
        << ": кольцо " << disk
        << " со стержня " << from
        << " на стержень " << to << endl;

    printTowers();
}

// Рекурсивное решение задачи о Ханойской башне
void solveHanoi(int diskCount, int from, int to, int auxiliary)
{
    if (diskCount == 1)
    {
        moveDisk(from, to);
    }
    else
    {
        solveHanoi(diskCount - 1, from, auxiliary, to);

        moveDisk(from, to);

        solveHanoi(diskCount - 1, auxiliary, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Начальная расстановка колец на первом стержне
    for (int i = 0; i < N; i++)
        towers[0][i] = N - i;

    cout << "Решение задачи о Ханойской башне" << endl;
    cout << "Количество колец: " << N << endl;
    cout << "Перенос со стержня 1 на стержень 3" << endl;

    cout << endl << "Начальное состояние:" << endl;
    printTowers();

    // Запуск рекурсивного алгоритма
    solveHanoi(N, 1, 3, 2);

    cout << endl;
    cout << "Общее количество перемещений: "
        << moveCount << endl;

    return 0;
}
