#include "SortStrategy.h"

std::string InsertionSort::sort(AbstractTable* t) {
	 int j;
	 //ustawienie i na kolejnych miejscach w tablicy
	 for (int i = 1; i < t->getSize(); i++) {
		 j = i;
		 //"przesuwanie" mniejszych wartoœci w lewo do indeksu 0
		 while (j > 0 && t->compare(j - 1, j) == 1) {
			 t->swap(j - 1, j);
			 j--;
		 }
	 }
	 return t->toString();
}

std::string HeapSort::sort(AbstractTable* t)
{
    heapSize = t->getSize() - 1;
    for (int i = floor(heapSize / 2); i >= 0; i--) {
        heapify(t, i);
    }

    while(heapSize > 0) {
        t->swap(0, heapSize);
        heapSize--;
        heapify(t, 0);
    }

    return t->toString();
}

void HeapSort::heapify(AbstractTable* t, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare left child with root
    if (left < heapSize + 1 && t->compare(left, largest) == 1)
        largest = left;

    // Compare right child with largest so far
    if (right < heapSize + 1 && t->compare(right, largest) == 1)
        largest = right;

    // If largest is not root
    if (largest != index) {
        t->swap(index, largest);
        std::cout << t->toString();
        // Recursively heapify the affected sub-tree
        heapify(t, largest);
    }
}

std::string QuickSort::sort(AbstractTable* t)
{
    quickSort(t, 0, t->getSize() - 1);
    return t->toString();
}

void QuickSort::quickSort(AbstractTable* t, int low, int high)
{
    if (low < high) {
        int p = partition(t, low, high);

        quickSort(t, low, p - 1);
        quickSort(t, p + 1, high);
    }
}

int QuickSort::partition(AbstractTable* t, int low, int high)
{
    int pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (t->compare(pivot, j) == 0) {
            i++;
            t->swap(i, j);
        }
    }
    t->swap(i + 1, high);

    return i + 1;
}
