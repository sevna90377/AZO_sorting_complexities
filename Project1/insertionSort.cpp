#include <iostream>
#include <iterator>



void insertionSortInt(int arr_name[], int arr_len)
{
	int card_to_insert;												// "karta" któr¹ przemieszczamy
	int counter;													// licznik do loopa
	for (counter = 1; counter < arr_len; counter++)				//loop siê dzieje z pominiêciem "zerowego" elementu 
	{
		card_to_insert = arr_name[counter];											//bierzemy kartê
		int counter_inner = counter;
		while (counter_inner > 0 && arr_name[counter_inner - 1] > card_to_insert)		//porównujemy czy jest mniejsza od poprzedniej 
		{
			arr_name[counter_inner] = arr_name[counter_inner - 1];					//przesuwamy kartê któr¹ w³aœnie porównaliœmy
			counter_inner--;														//zajmujemy siê wczeœniejsz¹
		}
		arr_name[counter_inner] = card_to_insert;									//jeœli nasza karta jest wiêksza ni¿ porównywana to dajemy j¹ na to miejsce
	}
}

void insertionSortFloat(float arr_name[], int arr_len)
{
	float card_to_insert;												// "karta" któr¹ przemieszczamy
	int counter;													// licznik do loopa
	for (counter = 1; counter < arr_len; counter++);				//loop siê dzieje z pominiêciem "zerowego" elementu 
	{
		card_to_insert = arr_name[counter];											//bierzemy kartê
		int counter_inner = counter;
		while (counter_inner > 0 && arr_name[counter_inner - 1] > card_to_insert)		//porównujemy czy jest mniejsza od poprzedniej 
		{
			arr_name[counter_inner] = arr_name[counter_inner - 1];					//przesuwamy kartê któr¹ w³aœnie porównaliœmy
			counter_inner--;														//zajmujemy siê wczeœniejsz¹
		}
		arr_name[counter_inner] = card_to_insert;									//jeœli nasza karta jest wiêksza ni¿ porównywana to dajemy j¹ na to miejsce
	}

}