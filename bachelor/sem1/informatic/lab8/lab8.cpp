#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>
#include <windows.h>
using namespace std;

struct Employee
{
    char surname[40];
    char name[40];
    char patronymic[40];
    char position[40];
    int birthYear;
    float salary;
};

void inputEmployee(Employee& e)
{
    cout << "Фамилия: ";
    cin >> e.surname;

    cout << "Имя: ";
    cin >> e.name;

    cout << "Отчество: ";
    cin >> e.patronymic;

    cout << "Должность: ";
    cin >> e.position;

    cout << "Год рождения: ";
    cin >> e.birthYear;

    cout << "Зарплата: ";
    cin >> e.salary;
}

void printFile()
{
    FILE* fp;
    fopen_s(&fp, "employees.dat", "rb");

    if (fp == NULL)
    {
        cout << "Ошибка открытия файла!";
        return;
    }

    Employee e;

    cout << "\nСписок сотрудников:\n";

    while (fread(&e, sizeof(Employee), 1, fp) == 1)
    {
        cout << "\n" << e.surname << " "
            << e.name << " " << e.patronymic
            << "\nДолжность: " << e.position
            << "\nГод рождения: " << e.birthYear
            << "\nЗарплата: " << e.salary << endl;
    }

    fclose(fp);
}

bool deleteEmployee(char surname[])
{
    FILE* fp;
    FILE* temp;

    fopen_s(&fp, "employees.dat", "rb");
    fopen_s(&temp, "temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        cout << "Ошибка открытия файла!";

        if (fp != NULL) fclose(fp);
        if (temp != NULL) fclose(temp);

        return false;
    }

    Employee e;
    bool found = false;

    while (fread(&e, sizeof(Employee), 1, fp) == 1)
    {
        if (strcmp(e.surname, surname) == 0 && !found)
            found = true;
        else
            fwrite(&e, sizeof(Employee), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (!found)
    {
        remove("temp.dat");
        cout << "Сотрудник не найден!\n";
        return false;
    }

    remove("employees.dat");

    if (rename("temp.dat", "employees.dat") != 0)
        cout << "Ошибка переименования файла!";

    cout << "Сотрудник удалён!\n";
    return true;
}

void addEmployee(int number, Employee newEmp)
{
    FILE* fp;
    FILE* temp;

    fopen_s(&fp, "employees.dat", "rb");
    fopen_s(&temp, "temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        cout << "Ошибка открытия файла!";

        if (fp != NULL) fclose(fp);
        if (temp != NULL) fclose(temp);

        return;
    }

    Employee e;
    int i = 0;

    while (fread(&e, sizeof(Employee), 1, fp) == 1)
    {
        fwrite(&e, sizeof(Employee), 1, temp);
        i++;

        if (i == number)
            fwrite(&newEmp, sizeof(Employee), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("employees.dat");

    if (rename("temp.dat", "employees.dat") != 0)
        cout << "Ошибка переименования файла!";

    cout << "Сотрудник добавлен!\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Employee e;
    int n;

    cout << "Введите количество сотрудников: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Неверное количество!";
        return 0;
    }

    FILE* fp;
    fopen_s(&fp, "employees.dat", "wb");

    if (fp == NULL)
    {
        cout << "Ошибка создания файла!";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nСотрудник №" << i + 1 << endl;
        inputEmployee(e);
        fwrite(&e, sizeof(Employee), 1, fp);
    }

    fclose(fp);

    printFile();

    char surname[40];

    cout << "\nВведите фамилию для удаления: ";
    cin >> surname;

    if (deleteEmployee(surname))
        n--;

    printFile();

    if (n == 0)
    {
        cout << "Нет сотрудников для добавления после них!";
        return 0;
    }

    int number;

    cout << "\nПосле какого сотрудника добавить нового? ";
    cin >> number;

    if (number < 1 || number > n)
    {
        cout << "Неверный номер!";
        return 0;
    }

    cout << "\nВведите данные нового сотрудника:\n";
    inputEmployee(e);

    addEmployee(number, e);

    printFile();

    return 0;
}