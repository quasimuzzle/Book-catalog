#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include "Struct.h"
#include "Menu.h"
#include "Add.h"
#include "Viewing.h"
#include "Search.h"
#include "Exit.h"

	using namespace std;
	
int main()
{
	setlocale(LC_ALL, "rus");
	fstream file;
	bool f = true;
	const char* doc = "BOOKCATALOG.dat";
	int choise;
	while (f) {
		menu(); // вызов меню
		cin >> choise;
		switch (choise)
		{
		case 1: // Добавление записи
			getchar();
			cout << "Введите название книги: "; cin.getline(book.name, 50);
			cout << "Введите автора книги: "; cin.getline(book.author, 50);
			cout << "Введите количество страниц: "; cin >> book.numberOfPages;
			cout << "Введите цену книги(руб): "; cin >> book.price;
			cout << "Введите год выпуска: "; cin >> book.year;

			add(doc); // Add.h
			break;
		case 2: // Просмотр записей
			viewing(doc); // Prosmotr.h
			break;
		case 3: // Поиск записей
			search(doc); // Poisk.h
			break;
		case 4: // Выход
			f = exit(); 
			break;
		default:
			cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
			break;
		}
	}
	return 0;
}
