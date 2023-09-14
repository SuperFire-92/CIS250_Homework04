#include "SortList.h"

SortList::SortList()
{

}
//Overloaded constructor sets the unsortedList to the given array
SortList::SortList(Person l[])
{
	for (int i = 0; i < SIZE; i++)
	{
		unsortedList[i] = l[i];
	}
}

void SortList::bubbleSort()
{
	bool hasSwapped = true;
	//Starts by putting unsorted list into the sortedList object
	for (int i = 0; i < SIZE; i++)
	{
		sortedList[i] = unsortedList[i];
	}
	//Looping SIZE amount of times, starts from the end of the array until it pushed the smallest number to the front,
	//then repeats ending that loop at the second spot in the array until the array is fully sorted
	for (int i = 0; i < SIZE && hasSwapped == true; i++)
	{
		hasSwapped = false;
		for (int j = SIZE - 1; j > i; j--)
		{
			Person curPerson = sortedList[j];
			Person prePerson = sortedList[j - 1];
			if (curPerson.getId() < prePerson.getId())
			{
				hasSwapped = true;
				sortedList[j] = prePerson;
				sortedList[j - 1] = curPerson;
			}
		}
	}
}

void SortList::insertionSort()
{
	bool hasSwapped = true;
	//Starts by putting unsorted list into the sortedList object
	for (int i = 0; i < SIZE; i++)
	{
		sortedList[i] = unsortedList[i];
	}
	//Looping SIZE amount of times, starts from the beginning of the array, and pushes objects backwards into it until
	//they are in position.
	for (int i = 0; i < SIZE; i++)
	{
		hasSwapped = true;
		for (int j = i; j > 0 && hasSwapped == true; j--)
		{
			hasSwapped = false;
			Person curPerson = sortedList[j];
			Person prePerson = sortedList[j - 1];
			if (curPerson.getId() < prePerson.getId())
			{
				hasSwapped = true;
				sortedList[j] = prePerson;
				sortedList[j - 1] = curPerson;
			}
		}
	}
}

//Returns a person based off the requested position in the list
Person SortList::getUnsortedPerson(int i) const
{
	return unsortedList[i];
}
//Returns a person based off the requested position in the list
Person SortList::getSortedPerson(int i) const
{
	return sortedList[i];
}

//Sets the unsortedList to the given array
void SortList::setUnsortedList(Person l[])
{
	for (int i = 0; i < SIZE; i++)
	{
		unsortedList[i] = l[i];
	}
}