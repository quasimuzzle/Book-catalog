#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h> 
#include <fstream>

using namespace std;

struct BOOKCATALOG {
	char name[50], author[50];
	int numberOfPages, price, year;
};

BOOKCATALOG BOOK;

int main()
{
	setlocale(LC_ALL, "rus");
	fstream file;
	bool f = true,
		find = false;
	const char* doc = " bookcatalog.dat";
	char nameOfString[50]; 
	int choise,
		searchByNumber; 	
	double searchByDouble; 
	while (f) {
		cout << "1 - Новая запись" << endl;
		cout << "2 - Просмотр записей" << endl;
		cout << "3 - Поиск по записям" << endl;
		cout << "4 - выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			getchar();
			cout << "Введите название книги: "; cin.getline(BOOK.name, 50);
			cout << "Введите автора книги: "; cin.getline(BOOK.author, 50);
			cout << "Введите количество страниц: "; cin >> BOOK.numberOfPages;
			cout << "Введите цену книги: "; cin >> BOOK.price;
			cout << "Введите год выпуска книги: "; cin >> BOOK.year;

			file.open(doc, ios_base::app | ios_base::binary);
			if (!file.is_open())
				cout << "Файл не может быть открыт!\n";
			else {
				file.write((char*)&BOOK, sizeof(BOOKCATALOG));
			}
			file.close();
			break;
		case 2:
			file.open(doc, ios_base::in | ios_base::binary);
			if (!file.is_open())
				cout << "Файл не может быть открыт!\n";
			else {
				cout << "Все записи:\nНазвание                      \tАвтор книги           \tКол-во страниц     \t Цена книги    \tГод выпуска\n";
				while (true)
				{
					file.read((char*)&BOOK, sizeof(BOOKCATALOG));
					if (!file.eof())
						cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
					else
						break;
                }
				file.close();
				break;
			}
			break;
		case 3:
			int filter_option;
			cout << "Фильтры:\n"
				<< "\t1 - Поиск по названию книги\n"
				<< "\t2 - Поиск по автору книги\n"
				<< "\t3 - Поиск по количеству страниц\n"
				<< "\t4 - Поиск по цене книги\n"
				<< "\t5 - Поиск по году выпуска\n";
			cout << "Какой фильтр применить? "; cin >> filter_option;

			switch (filter_option) // выбор фильтра поиска
			{
			case 1:
				getchar();
				find = false;
				cout << "Введите название книги: "; cin.getline(nameOfString, 50);
				file.open(doc, ios_base::in | ios_base::binary);
				if (!file.is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
					while (true)
					{
						file.read((char*)&BOOK, sizeof(BOOKCATALOG));
						if (!file.eof()) {
							if (strcmp(BOOK.name, nameOfString) == 0)
							{
								cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
								find = true;
							}
						}
						else
							break;
					}
					if (!find)
						cout << "Записей не найдено.\n";
					file.close();
					break;
				}
			case 2:
				getchar();
				find = false;
				cout << "Введите автора книги: "; cin.getline(nameOfString, 50);
				file.open(doc, ios_base::in | ios_base::binary);
				if (!file.is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
					while (true)
					{
						file.read((char*)&BOOK, sizeof(BOOKCATALOG));
						if (!file.eof()) {
							if (strcmp(BOOK.author, nameOfString) == 0)
							{
								cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
								find = true;
							}
                     }
						else
							break;
					}
					if (!find)
						cout << "Записей не найдено.\n";
					file.close();
					break;
				}
			case 3:
				getchar();
				find = false;
				int oper;
				file.open(doc, ios_base::in | ios_base::binary);
				if (!file.is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
					switch (oper)
					{
					case 1:
						cout << "Введите количество страниц: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.numberOfPages == searchByDouble)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 2:
						cout << "Введите количество страниц: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.numberOfPages >= searchByDouble)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 3:
						cout << "Введите количество страниц: "; cin >> searchByDouble;                       
                        cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.numberOfPages <= searchByDouble)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					default:
						break;
					}
				}
				break;
			case 4:
				getchar();
				find = false;
				file.open(doc, ios_base::in | ios_base::binary);
				if (!file.is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
					switch (oper)
					{
					case 1:
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.price == searchByDouble)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 2:
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.price >= searchByDouble)
                                {
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 3:
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.price <= searchByDouble)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					default:
						break;
					}
				}
				break;
			case 5:
				getchar();
				find = false;
				file.open(doc, ios_base::in | ios_base::binary);
				if (!file.is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
					switch (oper)
					{
					case 1:
						cout << "Введите год выпуска: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.year == searchByNumber)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
                                break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 2:
						cout << "Введите год выпуска: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.year >= searchByNumber)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					case 3:
						cout << "Введите год выпуска: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file.read((char*)&BOOK, sizeof(BOOKCATALOG));
							if (!file.eof()) {
								if (BOOK.year <= searchByNumber)
								{
									cout << BOOK.name << "\t\t" << BOOK.author << "\t\t" << BOOK.numberOfPages << "\t\t" << BOOK.price << "\t\t" << BOOK.year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file.close();
						break;
					default:
						break;
					}
				}
			}
			break;
		case 4:
			f = false;
			break;
		default:
			cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
