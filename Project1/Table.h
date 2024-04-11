#pragma once

#include <string>
#include <fstream>
#include <sstream>

class AbstractTable 
{
public:

    //funckja zwracaj�ca wska�nik na obiekt klasy potomnej AbstractTable o odpowiednim typie danych
    static AbstractTable* createTable(bool isFloat);
    //wirtualny destruktor zabezpiecza przed wywo�aniem destruktora klasy bazowej przy korzystaniu ze wska�nika na klas� bazow�
    virtual ~AbstractTable() = 0;

    //metody wirtualne, kt�re b�d� wykorzystywane przez algorytmy sortuj�ce
    virtual int getSize() const = 0;
    virtual int compare(int firstIndex, int secondIndex) const = 0;
    virtual void swap(int firstIndex, int secondIndex) = 0;

    //funkcje odpowiedzialne za zape�nianie tablicy danymi
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

	Table() : headPointer(nullptr), tableLength(0) {	}	//domy�lny konstruktor inicjalizuje wska�nik na NULLPTR i zmienn� typu int na 0

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
            //Alokacja pami�ci na tablic� wi�ksz� o jeden element
            T* newPointer = new T[tableLength + 1];

            //Przepisanie warto�ci do nowej tablicy wraz z dodawanym elementem
            for (int i = 0; i < index; i++) {
                newPointer[i] = headPointer[i];
            }
            newPointer[index] = value;
            for (int i = index; i < tableLength; i++) {
                newPointer[i + 1] = headPointer[i];
            }

            //Zwolnienie pami�ci po poprzedniej tablicy i przypisanie nowego adresu wska�nikowi na pierwszy element tablicy
            delete headPointer;
            headPointer = newPointer;

            //Inkrementacja zmiennej przechowuj�cej rozmiar tablicy
            tableLength++;
        }
    };
    void deleteAt(int index) {

        if (tableLength > 0 && index >= 0 && index < tableLength) {
            //Alokacja pami�ci na tablic� mniejsz� o jeden element
            T* newPointer = new T[tableLength - 1];

            //Przepisanie do nowej tablicy wynik�w z pomini�ciem usuwanego elementu
            for (int i = 0; i < index; i++) {
                newPointer[i] = headPointer[i];
            }
            for (int i = index; i < tableLength - 1; i++) {
                newPointer[i] = headPointer[i + 1];
            }

            //Zwolnienie pami�ci po poprzedniej tablicy i przypisanie wska�nikowi na pierszy element tablicy nowego adresu
            delete headPointer;
            headPointer = newPointer;

            //Dekrementacja zmiennej przechowuj�cej rozmiar tablicy
            tableLength--;
        }
    };
    void deleteAll() {

        //Usuni�cie element�w z tablicy
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
            //usuni�cie ewentualnych warto�ci ju� obecnych w tablicy
            deleteAll();

            //pobranie ilo�ci warto�ci do odczytania z pierwszej linijki pliku
            myFile >> amount;

            //dodanie do tablicy wszystkich warto�ci
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

    std::string toString() const override{    //TU TE� POZMIENIAJ TEKSTY (NA POMARA�CZOWO)
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

