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
			cout << "Enter the title of the book: "; cin.getline(book.name, 50);
			cout << "Enter the author of the book: "; cin.getline(book.author, 50);
			cout << "Enter number of pages: "; cin >> book.numberOfPages;
			cout << "nter the price of the book: "; cin >> book.price;
			cout << "Enter the year of publication of the book: "; cin >> book.year;

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
			cout << "This command does not exist, please make sure you spell it correctly. " << endl;
			break;
		}
	}
	return 0;
}
