#include <iostream>
#include <clocale>
using namespace std;

int moveCount = 0;

void Hanoi(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        moveCount++;
        cout << "Ход " << moveCount
            << ": переместить кольцо 1 со стержня "
            << from << " на стержень " << to << endl;
    }
    else
    {
        Hanoi(n - 1, from, aux, to);

        moveCount++;
        cout << "Ход " << moveCount
            << ": переместить кольцо " << n
            << " со стержня " << from
            << " на стержень " << to << endl;

        Hanoi(n - 1, aux, to, from);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n = 5;

    cout << "Решение задачи о Ханойской башне" << endl;
    cout << "Количество колец: " << n << endl;
    cout << "Перемещение со стержня 1 на стержень 3"
        << endl << endl;

    Hanoi(n, 1, 3, 2);

    cout << endl;
    cout << "Общее количество перемещений: "
        << moveCount << endl;

    return 0;
}