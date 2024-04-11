#pragma once

#include <string>
#include <fstream>
#include <sstream>

class AbstractTable 
{
public:

    //funckja zwracaj¹ca wskaŸnik na obiekt klasy potomnej AbstractTable o odpowiednim typie danych
    static AbstractTable* createTable(bool isFloat);
    //wirtualny destruktor zabezpiecza przed wywo³aniem destruktora klasy bazowej przy korzystaniu ze wskaŸnika na klasê bazow¹
    virtual ~AbstractTable() = 0;

    //metody wirtualne, które bêd¹ wykorzystywane przez algorytmy sortuj¹ce
    virtual int getSize() const = 0;
    virtual int compare(int firstIndex, int secondIndex) const = 0;
    virtual void swap(int firstIndex, int secondIndex) = 0;

    //funkcje odpowiedzialne za zape³nianie tablicy danymi
    virtual int loadFromFile(std::string filename) = 0;
    virtual void generateTable(int tableLength) = 0;

    virtual std::string toString() const = 0;
};

template <typename T>
class Table : public AbstractTable
{
private:
	T* headPointer;
	int tableLength;

public:

	Table() : headPointer(nullptr), tableLength(0) {	}	//domyœlny konstruktor inicjalizuje wskaŸnik na NULLPTR i zmienn¹ typu int na 0

	~Table() {
		delete[]headPointer;
	};


    int getSize() const override {
        return tableLength;
    }
	int compare(int firstIndex, int secondIndex) const override{
        if (firstIndex >= 0 && firstIndex < tableLength && secondIndex >= 0 && secondIndex < tableLength) {
            return headPointer[firstIndex] > headPointer[secondIndex] ? 1 : 0;
        }
        return -1;
	}
	void swap(int firstIndex, int secondIndex) override {	//TU POZMIENIAJ NAZWY ZMIENNYCH
		if (firstIndex >= 0 && firstIndex < tableLength && secondIndex >= 0 && secondIndex < tableLength) {
			T holder = headPointer[firstIndex];
			headPointer[firstIndex] = headPointer[secondIndex];
			headPointer[secondIndex] = holder;
		}
	};
    
    /*
    int getIntAt(int index) const override {
        if (std::is_same<T, int>::value) {
            return headPointer[index];
        }
        else {
            throw std::runtime_error("Mixed types");
        }
    }
    float getFloatAt(int index) const override {
        if (std::is_same<T, float>::value) {
            return headPointer[index];
        }
        else {
            throw std::runtime_error("Mixed types");
        }
    }
    void setAt(int index, int value) override {
        if (std::is_same<T, int>::value) {
            if (index >= 0 && index < tableLength) {
                headPointer[index] = value;
            }
            else {
                throw std::out_of_range("Index out of range");
            }
        }
        else {
            throw std::runtime_error("Mixed types");
        }
    }
    void setAt(int index, float value) override {
        if (std::is_same<T, float>::value) {
            if (index >= 0 && index < tableLength) {
                headPointer[index] = value;
            }
            else {
                throw std::out_of_range("Index out of range");
            }
        }
        else {
            throw std::runtime_error("Mixed types");
        }
    }
    */

    void addValue(int index, T value) {

        if (index >= 0 && index <= tableLength) {
            //Alokacja pamiêci na tablicê wiêksz¹ o jeden element
            T* newPointer = new T[tableLength + 1];

            //Przepisanie wartoœci do nowej tablicy wraz z dodawanym elementem
            for (int i = 0; i < index; i++) {
                newPointer[i] = headPointer[i];
            }
            newPointer[index] = value;
            for (int i = index; i < tableLength; i++) {
                newPointer[i + 1] = headPointer[i];
            }

            //Zwolnienie pamiêci po poprzedniej tablicy i przypisanie nowego adresu wskaŸnikowi na pierwszy element tablicy
            delete headPointer;
            headPointer = newPointer;

            //Inkrementacja zmiennej przechowuj¹cej rozmiar tablicy
            tableLength++;
        }
    };
    void deleteAt(int index) {

        if (tableLength > 0 && index >= 0 && index < tableLength) {
            //Alokacja pamiêci na tablicê mniejsz¹ o jeden element
            T* newPointer = new T[tableLength - 1];

            //Przepisanie do nowej tablicy wyników z pominiêciem usuwanego elementu
            for (int i = 0; i < index; i++) {
                newPointer[i] = headPointer[i];
            }
            for (int i = index; i < tableLength - 1; i++) {
                newPointer[i] = headPointer[i + 1];
            }

            //Zwolnienie pamiêci po poprzedniej tablicy i przypisanie wskaŸnikowi na pierszy element tablicy nowego adresu
            delete headPointer;
            headPointer = newPointer;

            //Dekrementacja zmiennej przechowuj¹cej rozmiar tablicy
            tableLength--;
        }
    };
    void deleteAll() {

        //Usuniêcie elementów z tablicy
        while (tableLength > 0) {
            deleteAt(0);
        }
    };

    int loadFromFile(std::string filename) override {
        std::ifstream myFile;
        int amount;
        T value;

        myFile.open(filename);

        if (myFile.is_open())
        {
            //usuniêcie ewentualnych wartoœci ju¿ obecnych w tablicy
            deleteAll();

            //pobranie iloœci wartoœci do odczytania z pierwszej linijki pliku
            myFile >> amount;

            //dodanie do tablicy wszystkich wartoœci
            for (int i = 0; i < amount; i++) {
                myFile >> value;
                addValue(i, value);
            }

            myFile.close();

            return 0;
        }
        else {
            return 1;
        }
    };

    void generateTable(int tableLength);

    std::string toString() const override{    //TU TE¯ POZMIENIAJ TEKSTY (NA POMARAÑCZOWO)
        std::stringstream ss;
        ss << "\nTablica --> [ ";
        for (int i = 0; i < tableLength; i++) {
            if (i != 0) {
                ss << ", ";
            }
            ss << headPointer[i];
        }
        ss << " ]\n";
        return ss.str();
    }
};

