#include "Header.h"

void Shifr()
{
	setlocale(LC_ALL, "ru");
	ifstream in("data.txt");
	ofstream out("vremenn.txt");
	char key = '=';
	string a;
	if (in.is_open())
	{
		cout << "Все ОК! Файл открыт!\n\n" << endl;
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
	}
	while (getline(in, a))
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = a[i] ^ key;
			out << a[i];
		}
		out << endl;
	}
	in.close();
	out.close();
	remove("data.txt");
	rename("vremenn.txt", "data.txt");
	ifstream in2("Tests.txt");
	ofstream out2("vremenn.txt");
	if (in2.is_open())
	{
		cout << "Все ОК! Файл открыт!\n\n" << endl;
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
	}
	while (getline(in2, a))
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = a[i] ^ key;
			out2 << a[i];
		}
		out2 << endl;
	}
	in2.close();
	out2.close();
	remove("Tests.txt");
	rename("vremenn.txt", "Tests.txt");
}

void clear()
{
	system("cls");
}