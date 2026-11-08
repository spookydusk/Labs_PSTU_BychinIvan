#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string str;
    string word = "";
    string longest = "";
    string shortest = "";

    cout << "Введите строку: ";
    getline(cin, str);

    bool firstWord = true;

    for (int i = 0; i <= str.length(); i++)
    {

        if (i < str.length())
        {
            if (str[i] != ' ')
            {
                word += str[i];
            }
            else
            {
                if (word.length() > 0)
                {
                    if (firstWord)
                    {
                        longest = word;
                        shortest = word;
                        firstWord = false;
                    }
                    else
                    {
                        if (word.length() > longest.length())
                        {
                            longest = word;
                        }

                        if (word.length() < shortest.length())
                        {
                            shortest = word;
                        }
                    }

                    word = "";
                }
            }
        }
        else
        {
            if (word.length() > 0)
            {
                if (firstWord)
                {
                    longest = word;
                    shortest = word;
                    firstWord = false;
                }
                else
                {
                    if (word.length() > longest.length())
                    {
                        longest = word;
                    }

                    if (word.length() < shortest.length())
                    {
                        shortest = word;
                    }
                }
            }
        }
    }

    if (firstWord)
    {
        cout << "Строка не содержит слов." << endl;
    }
    else
    {
        cout << "Самое длинное слово: " << longest << endl;
        cout << "Самое короткое слово: " << shortest << endl;
    }

    return 0;
}