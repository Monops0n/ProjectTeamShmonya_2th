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
	ifstream in("Tests.txt");
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
	remove("Tests.txt");
	rename("vremenn.txt", "Tests.txt");
}
void teacher()
{
	cout << "Hello" << endl;
}

void clear()
{
	system("cls");
}