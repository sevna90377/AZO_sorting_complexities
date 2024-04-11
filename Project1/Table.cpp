#include "Table.h"

AbstractTable* AbstractTable::createTable(bool isFloat) {
    if (isFloat) {
        return new Table<float>();
    }
    else {
        return new Table<int>();
    }
}

//implementacja destruktora klasy abstrakcyjnej jest konieczna ze wzglêdu na wywo³anie go po destruktorze klas potomnych
AbstractTable::~AbstractTable() { }


//implementacja odpowiednich funkcji do losowania wartoœci tablicy
template<> void Table<int>::generateTable(int tableLength) {

    //usuniêcie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pamiêci
    headPointer = new int[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zape³nienie tablicy losowymi wartoœciami (nieokreœlony przedzia³)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = rand();
    }
}

template<> void Table<float>::generateTable(int tableLength) {

    //usuniêcie obecnej tablicy
    deleteAll();
    delete headPointer;

    //alokacja pamiêci
    headPointer = new float[tableLength];
    this->tableLength = tableLength;

    //pobranie ziarna dla generatora
    srand((unsigned int)time(0));

    //zape³nienie tablicy losowymi wartoœciami (przedzia³ od 0.0 do 10.0)
    for (int i = 0; i < tableLength; i++) {
        headPointer[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));
    }
}
