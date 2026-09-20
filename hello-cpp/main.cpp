#include <iostream>
using namespace std;
int main()  {

    int a, b, res = 0;
    char znak;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Which operation u want? ";
    cin >> znak;
    switch(znak) {
    case'*': res = a * b; break;
    case'/': res = a / b; break;
    case'+': res = a + b; break;
    case'-': res = a - b; break;
    default:
    cout << "Error! ";
    return 1;
    }
    cout << "Itogovoye number: " << res;
    return 0;
    }