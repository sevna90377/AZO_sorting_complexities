#include "Menu.h"


int Menu::main()
{
	std::cout << "PROGRAM SORTUJACY :]\n";
	std::cout << "Zaczynamy od stworzenia tablicy!\n";
	tableMenu();
	char opt;
	do {
		std::cout << "\n\n=== === === === ===\n";
		std::cout << table->toString();
		std::cout << "\n1 - zmien dane\n";
		std::cout << "2 - wybierz algorytm\n";
		std::cout << "0 - exit\n";
		std::cout << "> ";
		opt = _getche();
		switch (opt) {
		case '1':
			tableMenu();
			break;
		case '2':
			algorithmMenu();
			break;
		default:
			break;
		}
	} while (opt != '0');

	return 0;
}

void Menu::tableMenu()	//TU POZMIENIAJ TEKSTY I TO WYRA¯ENIE Z PYTAJNIKIEM NA IF ZWYK£Y
{
	char opt;
	bool isFloat;

	std::string filename;
	int arraySize;

	//zwolnienie pamiêci po poprzednim obiekcie
 	if (table != nullptr) {
		delete table;
	}

	std::cout << "\nWybierz rodzaj danych:\n";
	std::cout << "1 - int\n";
	std::cout << "2 - float\n";
	std::cout << "> ";
	opt = _getche();
	isFloat = (opt == '2') ? true : false;

	//utworzenie nowego obiektu klasy Table o odpowiednim typie danych
	table = AbstractTable::createTable(isFloat);

	std::cout << "\nWybierz sposob zapelnienia danymi:\n";
	std::cout << "1 - wczytaj\n";
	std::cout << "2 - losuj\n";
	std::cout << "> ";
	opt = _getche();

	switch (opt) {
	case '1':	//wczytywanie z pliku
		std::cout << "\nPodaj nazwe pliku\n";
		std::cin >> filename;
		if (table->loadFromFile(filename)) {
			std::cout << "Nie udalo sie otworzyc pliku";
			break;
		}
		break;
	case '2':	//losowanie zawartoœci
		std::cout << "\nPodaj rozmiar tablicy\n";
		std::cin >> arraySize;
		table->generateTable(arraySize);
		break;
	default:
		std::cout << "Zly wybor... nie utworzono tablicy!";
	}
}
void Menu::algorithmMenu() {
	char opt;
	InsertionSort* is;
	HeapSort* hs;
	QuickSort* qs;
	std::cout << "\nWybierz algorytm\n";
	std::cout << "1 - insertion sort\n";
	std::cout << "2 - heap sort\n";
	std::cout << "3 - quick sort\n";
	std::cout << "> ";
	opt = _getche();
	switch (opt) {
	case '1':
		is = new InsertionSort();
		std::cout << is->sort(table);
		break;
	case '2':
		hs = new HeapSort();
		std::cout << hs->sort(table);
		break;
	case '3':
		qs = new QuickSort();
		std::cout << qs->sort(table);
	}
}

int main(void) {
	Menu* menu = new Menu;
	return menu->main();
}
