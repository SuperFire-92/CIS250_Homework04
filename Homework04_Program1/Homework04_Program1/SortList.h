#pragma once
#include "Person.h"
class SortList
{
private:
	int static const SIZE = 577;
	Person unsortedList[SIZE];
	Person sortedList[SIZE];
public:
	SortList();
	SortList(Person[]);

	void bubbleSort();

	void insertionSort();

	Person getUnsortedPerson(int) const;
	Person getSortedPerson(int) const;

	void setUnsortedList(Person[]);
};

