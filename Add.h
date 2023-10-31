#ifndef ADD_H
#define ADD_H
#include <iostream>

using namespace std;

void add(const char* doc)
{
	fstream file;
	file.open(doc, ios_base::app | ios_base::binary);
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		file.write((char*)&book, sizeof(BOOKCATALOG)); 
	}
	file.close();
}

#endif //ADD_H
