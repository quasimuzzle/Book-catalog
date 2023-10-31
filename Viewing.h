#ifndef VIEWING_H
#define VIEWING_H
#include <iostream>

using namespace std;

void viewing(const char* doc)
{
	ifstream file;
	file.open(doc, ios_base::in | ios_base::binary);
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		cout << "Все записи:\nНазвание\t\t\t\tАвтор книги\t\tКол-во страниц\t\tЦена\tГод выпуска\n\n\n";
		while (true)
		{
			file.read((char*)&book, sizeof(BOOKCATALOG));
			if (!file.eof())	
				cout << book.name << "\t\t" << book.author << "\t\t" << book.numberOfPages << "\t\t" << book.price << "\t\t" << book.year << endl;
			else
				break;
		}
		file.close();
	}
}
#endif //VIEWING_H
