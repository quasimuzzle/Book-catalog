#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
using namespace std;

void search(const char* doc)
{
	ifstream file;
	bool find = false;
	char nameOfString[50];
	int filter_option, searchByNumber;
	double searchByDouble;
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
				file.read((char*)&book, sizeof(BOOKCATALOG));
				if (!file.eof()) {
					if (strcmp(book.name, nameOfString) == 0)
					{
						cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
				file.read((char*)&book, sizeof(BOOKCATALOG));
				if (!file.eof()) {
					if (strcmp(book.author, nameOfString) == 0)
					{
						cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.numberOfPages == searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.numberOfPages >= searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.numberOfPages <= searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.price == searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.price >= searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.price <= searchByDouble)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.year == searchByNumber)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.year >= searchByNumber)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
					file.read((char*)&book, sizeof(BOOKCATALOG));
					if (!file.eof()) {
						if (book.year <= searchByNumber)
						{
							cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
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
	default:
		break;
	}
}

#endif //SEARCH_H

