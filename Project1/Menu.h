#pragma once

#include <iostream>
#include "Table.h"
#include "SortStrategy.h"
#include <conio.h>

class Menu
{
public:

	AbstractTable* table;

	Menu() : table(nullptr) {};
	~Menu() {
		delete table;
	}

	int main();

private:

	void tableMenu();
	void algorithmMenu();

	
};

