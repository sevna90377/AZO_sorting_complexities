#include <iostream>
#include <iterator>



void insertionSortInt(int arr_name[], int arr_len)
{
	int card_to_insert;												// "karta" kt�r� przemieszczamy
	int counter;													// licznik do loopa
	for (counter = 1; counter < arr_len; counter++)				//loop si� dzieje z pomini�ciem "zerowego" elementu 
	{
		card_to_insert = arr_name[counter];											//bierzemy kart�
		int counter_inner = counter;
		while (counter_inner > 0 && arr_name[counter_inner - 1] > card_to_insert)		//por�wnujemy czy jest mniejsza od poprzedniej 
		{
			arr_name[counter_inner] = arr_name[counter_inner - 1];					//przesuwamy kart� kt�r� w�a�nie por�wnali�my
			counter_inner--;														//zajmujemy si� wcze�niejsz�
		}
		arr_name[counter_inner] = card_to_insert;									//je�li nasza karta jest wi�ksza ni� por�wnywana to dajemy j� na to miejsce
	}
}

void insertionSortFloat(float arr_name[], int arr_len)
{
	float card_to_insert;												// "karta" kt�r� przemieszczamy
	int counter;													// licznik do loopa
	for (counter = 1; counter < arr_len; counter++);				//loop si� dzieje z pomini�ciem "zerowego" elementu 
	{
		card_to_insert = arr_name[counter];											//bierzemy kart�
		int counter_inner = counter;
		while (counter_inner > 0 && arr_name[counter_inner - 1] > card_to_insert)		//por�wnujemy czy jest mniejsza od poprzedniej 
		{
			arr_name[counter_inner] = arr_name[counter_inner - 1];					//przesuwamy kart� kt�r� w�a�nie por�wnali�my
			counter_inner--;														//zajmujemy si� wcze�niejsz�
		}
		arr_name[counter_inner] = card_to_insert;									//je�li nasza karta jest wi�ksza ni� por�wnywana to dajemy j� na to miejsce
	}

}