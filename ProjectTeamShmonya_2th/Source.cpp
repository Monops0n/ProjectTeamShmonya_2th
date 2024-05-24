#include "Header.h"

void main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Shifr();
    int zadanie;
    do
    {
        clear();
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|          Тестирование по курсу Программирование     | " << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|    1 - Войти как студент                            |" << endl;
        cout << "\t|    2 - Войти как преподаватель                      |" << endl;
        cout << "\t|    3 - ВЫХОД                                        |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
        cout << "\t";
        cin >> zadanie;
        switch (zadanie)
        {
        case 1: student(); break;
        case 2: teacher(); break;
        case 3: cout << "\tВыход из программы....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3) cout << "\tТакого варианта нет, попробуйте ещё раз..." << endl << endl; Sleep(1000);
    } while (zadanie != 7);
    Shifr();
    Sleep(1000);
}