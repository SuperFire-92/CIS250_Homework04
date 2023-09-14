//===============================================
//Name: Nicolaas Dyk
//Date: 03-28-2023
//Desc: Using bubble sorting and insertion
//      sorting to sort through a census list
//===============================================

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "SortList.h"
#include "time.h"
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void readCensus(Person[], int);
void displayList(SortList, int);

int main()
{
    //Make an array and it's size to hold the unsorted list
    int const SIZE = 577;
    Person unsortedList[SIZE];

    //Read the census list
    readCensus(unsortedList, SIZE);
    
    //fill a SortList object with the array
    SortList list(unsortedList);

    //string to store the user's input
    string userInput = "";

    //Ask the user what they wish to do
    cout << "This program is going to read a very large text file and sort it." << endl;
    cout << "Which sort would you like to perform?" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "Make your selection: ";
    while (userInput != "1" && userInput != "2")
    {
        cin >> userInput;
        if (userInput != "1" && userInput != "2")
        {
            cout << "Invalid Response (1 for Bubble, 2 for Insertion)" << endl;
        }
    }

    //Start the timer
    high_resolution_clock::time_point start = high_resolution_clock::now();
    //Bubble sort or Insertion sort depending on user choice
    if (userInput == "1")
    {
        list.bubbleSort();
    }
    else
    {
        list.insertionSort();
    }
    
    //End the timer
    high_resolution_clock::time_point end = high_resolution_clock::now();
    //Calculate the time it took
    duration<double, milli> time = end - start;

    displayList(list, SIZE);
    cout << endl;
    cout << "Time to sort:" << endl;
    cout << time.count() / 1000 << " Seconds" << endl;
    cout << time.count() / 1000 / 60 << " Minutes" << endl;
}

void readCensus(Person unsortedList[], int size)
{
    ifstream file;

    const string fileName = "CensusSmall.txt";
    string lineOfText;
    string curDataS;
    double curDataD;

    //int to keep track of what line we're on
    int i = 0;

    file.open(fileName);
    
    if (file)
    {
        //cout << "File Found" << endl;

        //Begin parsing the data
        while (getline(file, lineOfText))
        {
            //Get the name
            curDataS = lineOfText.substr(0, (lineOfText.find(' ')));
            unsortedList[i].setName(curDataS);

            //Delete the data in lineOfText up until the next piece of data
            lineOfText = lineOfText.substr(21);
            
            //Get the wage
            curDataD = stod(lineOfText.substr(0, (lineOfText.find(' '))));
            unsortedList[i].setWage(curDataD);

            //Delete the data in lineOfText up until the next piece of data
            lineOfText = lineOfText.substr(8);
            
            //Clear out any spare spaces
            while (lineOfText.at(0) == ' ')
            {
                lineOfText = lineOfText.substr(1);
            }
            //Get the id
            curDataD = stod(lineOfText.substr(0, (lineOfText.find(' '))));
            unsortedList[i].setId(curDataD);

            //Delete the data in lineOfText up until the next piece of data
            lineOfText = lineOfText.substr(lineOfText.find(' ') + 2);

            //Get the depId
            curDataD = stod(lineOfText);
            unsortedList[i].setDepId(curDataD);

            i++;
        }
    }
    else
    {
        //cout << "File Not Found" << endl;
    }
}

void displayList(SortList list, int size)
{
    //First display the first 10 entries in the list
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                         First 10                         " << endl;
    cout << "==========================================================" << endl;
    cout << "ID                       Name                       Hourly" << endl;
    cout << "==========================================================" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(25) << left << list.getSortedPerson(i).getId() << setw(27) << left << list.getSortedPerson(i).getName() << list.getSortedPerson(i).getWage() << endl;
    }
    //Then display the lsat 10 entries
    cout << "==========================================================" << endl;
    cout << "                         Last 10                         " << endl;
    cout << "==========================================================" << endl;
    cout << "ID                       Name                       Hourly" << endl;
    cout << "==========================================================" << endl;
    for (int i = size - 10; i < size; i++)
    {
        cout << setw(25) << left << list.getSortedPerson(i).getId() << setw(27) << left << list.getSortedPerson(i).getName() << list.getSortedPerson(i).getWage() << endl;
    }
}