#pragma once

#include "table.h"
#include <iostream>

class SortStrategy
{
public:
	virtual std::string sort(AbstractTable* t) = 0;
};

class InsertionSort : public SortStrategy {
public:
	std::string sort(AbstractTable* t) override;
};

class HeapSort : public SortStrategy {
public:
	std::string sort(AbstractTable* t) override;

private:
	int heapSize;

	void heapify(AbstractTable* t, int index);
};

class QuickSort : public SortStrategy {
public :
	std::string sort(AbstractTable* t) override;

private:
	void quickSort(AbstractTable* t, int low, int high);
	int partition(AbstractTable* t, int low, int high);

};