#include "Table.h"

AbstractTable* AbstractTable::createTable(bool isFloat) {
    if (isFloat) {
        return new Table<float>();
    }
    else {
        return new Table<int>();
    }
}

//implementacja destruktora klasy abstrakcyjnej jest konieczna ze wzgl�du na wywo�anie go po destruktorze klas potomnych
AbstractTable::~AbstractTable() { }


//implementacja odpowiednich funkcji do losowania warto�ci tablicy
template<> void Table<int>::generateTable(int tableLength) {

    //usuni�cie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pami�ci
    headPointer = new int[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zape�nienie tablicy losowymi warto�ciami (nieokre�lony przedzia�)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = rand();
    }
}

template<> void Table<float>::generateTable(int tableLength) {

    //usuni�cie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pami�ci
    headPointer = new float[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zape�nienie tablicy losowymi warto�ciami (przedzia� od 0.0 do 10.0)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));
    }
}
