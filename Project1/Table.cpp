#include "Table.h"

AbstractTable* AbstractTable::createTable(bool isFloat) {
    if (isFloat) {
        return new Table<float>();
    }
    else {
        return new Table<int>();
    }
}

//implementacja destruktora klasy abstrakcyjnej jest konieczna ze względu na wywołanie go po destruktorze klas potomnych
AbstractTable::~AbstractTable() { }


//implementacja odpowiednich funkcji do losowania wartości tablicy
template<> void Table<int>::generateTable(int tableLength) {

    //usunięcie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pamięci
    headPointer = new int[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zapełnienie tablicy losowymi wartościami (nieokreślony przedział)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = rand();
    }
}

template<> void Table<float>::generateTable(int tableLength) {

    //usunięcie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pamięci
    headPointer = new float[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zapełnienie tablicy losowymi wartościami (przedział od 0.0 do 10.0)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));
    }
}
