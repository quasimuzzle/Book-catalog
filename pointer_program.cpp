#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstring>
#include <fstream>

using namespace std;

typedef struct BOOKCATALOG
{
	char name[50], author[50];
	int numberOfPages, price, year;
}*BOOKBOOKCATALOG;

BOOKBOOKCATALOG BOOK;

int main()
{
	setlocale(LC_ALL, "rus");
	fstream* file;
	BOOK = new BOOKCATALOG;
	file = new fstream;
	bool f = true, // для повторного вызова меню
		find = false; // нашлась запись в бд или нет
	const char* doc = "bookcatalog.dat";
	char nameOfString[50]; // переменная для поиска по строке
	int choise,
		searchByNumber; // переменная для поиска по целочисленным значениям
	double searchByDouble; // переменная для поиска по значениям с плавающей точкой
	while (f) { // зацикленное воспроизведение меню
		cout << "1 - Новая запись" << endl;
		cout << "2 - Просмотр записей" << endl;
		cout << "3 - Поиск по записям" << endl;
		cout << "4 - выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: // добавление записи в бд
			getchar();
			cout << "Введите название книги: "; cin.getline(BOOK->name, 50);
			cout << "Введите автора книги: "; cin.getline(BOOK->author, 50);
			cout << "Введите количество страниц: "; cin >> BOOK->numberOfPages;
			cout << "Введите цену книги: "; cin >> BOOK->price;
			cout << "Введите год выпуска: "; cin >> BOOK->year;


			file->open(doc, ios_base::app | ios_base::binary);
			if (!file->is_open())
				cout << "Файл не может быть открыт!\n";
			else {
				file->write((char*)BOOK, sizeof(BOOKCATALOG));
			}
			file->close();
			break;
		case 2: // вывод всех записей в консоль
			file->open(doc, ios_base::in | ios_base::binary);
			if (!file->is_open())
				cout << "Файл не может быть открыт!\n";
			else {
				cout << "Все записи:\nНазвание\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
				while (true)
				{
					file->read((char*)BOOK, sizeof(BOOKCATALOG));
					if (!file->eof())
						cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
					else
						break;
				}
				file->close();
				break;
			}
			break;
		case 3: // поиск записей по фильтрам
			int filter_option; // выбор фильтра
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
				cout << "Введите название книги: "; cin.getline(nameOfString, 50);
				file->open(doc, ios_base::in | ios_base::binary);
				if (!file->is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
					while (true)
					{
						file->read((char*)BOOK, sizeof(BOOKCATALOG));
						if (!file->eof()) {
							if (strcmp(BOOK->name, nameOfString) == 0)
							{
								cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
								find = true;
							}
						}
						else
							break;
					}
					if (!find)
						cout << "Записей не найдено.\n";
					file->close();
					break;
				}
			case 2: // Поиск по модели
				getchar();
				cout << "Введите автора: "; cin.getline(nameOfString, 50);
				file->open(doc, ios_base::in | ios_base::binary);
				if (!file->is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
					while (true)
					{
						file->read((char*)BOOK, sizeof(BOOKCATALOG));
						if (!file->eof()) {
							if (strcmp(BOOK->author, nameOfString) == 0)
							{
								cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
								find = true;
							}
						}
						else
							break;
					}
					if (!find)
						cout << "Записей не найдено.\n";
					file->close();
					break;
				}
			case 3:
				getchar();
				int oper; // выбор подфильтра
				file->open(doc, ios_base::in | ios_base::binary);
				if (!file->is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper; // выбор подфильтра
					switch (oper) // поиск по подфильтру
					{
					case 1: // если введенное значние == заданному
						cout << "Введите количество страниц: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->numberOfPages == searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 2: // если значние >= заданного
						cout << "Введите количество страниц: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->numberOfPages >= searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 3: // если значние <= заданного
						cout << "Введите количество страниц: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->numberOfPages <= searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					default:
						break;
					}
				}
				break;
			case 4:
				getchar();
				file->open(doc, ios_base::in | ios_base::binary);
				if (!file->is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper; // выбор подфильтра
					switch (oper) // поиск по подфильтру
					{
					case 1: // если введенное значние == заданному
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->price == searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 2: // если значние >= заданного
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->price >= searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 3: // если значние <= заданного
						cout << "Введите цену: "; cin >> searchByDouble;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->price <= searchByDouble)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					default:
						break;
					}
				}
				break;
			case 5:
				getchar();
				file->open(doc, ios_base::in | ios_base::binary);
				if (!file->is_open())
					cout << "Файл не может быть открыт!\n";
				else {
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
					switch (oper)
					{
					case 1:
						cout << "Введите год: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->year == searchByNumber)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 2:
						cout << "Введите год: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->year >= searchByNumber)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					case 3:
						cout << "Введите год: "; cin >> searchByNumber;
						cout << "Название книги\tАвтор книги\tКол-во страниц\tЦена книги\tГод выпуска\n";
						while (true)
						{
							file->read((char*)BOOK, sizeof(BOOKCATALOG));
							if (!file->eof()) {
								if (BOOK->year <= searchByNumber)
								{
									cout << BOOK->name << "\t\t" << BOOK->author << "\t\t" << BOOK->numberOfPages << "\t\t" << BOOK->price << "\t\t" << BOOK->year << endl;
									find = true;
								}
							}
							else
								break;
						}
						if (!find)
							cout << "Записей не найдено.\n";
						file->close();
						break;
					default:
						break;
					}
				}
				break;
			default:
				break;
			}
			break;
		case 4: // выход из программы
			f = false;
			break;
		default:
			cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
			break;
		}
	}
	delete file;
	delete BOOK;
	return 0;
}
