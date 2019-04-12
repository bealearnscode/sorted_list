// Beatrix House

#include "sorted_list.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    
    // create an object of the SortedList class
    SortedList listSorted;
    
    // create input file to be read
    ifstream inputFile;
    
    // create a variable for the word read from each line
    string word;
    
    // open the file
   inputFile.open("words.in");
    
    // if the file exists
    if (inputFile.good())
    {
        // while there is a word to be read from the input file
        while(getline(inputFile, word))
        {
            // save the word inside the listOfWords object
            listSorted.Insert(word);
        }
    }
    
    listSorted.GetLength();
    
    // print the list of words
    listSorted.PrintList();
    
    // close the file
    inputFile.close();
    
    return 0;
}



// constructor
SortedList::SortedList()
{
    length = 0;
}

void SortedList::Insert(ItemType item)
{
    if(!(isFull())
    {
        if (values[length -1] > item) 
        {
            values[length] = values[length -1];
        }
        else
        {
            values[length] = item;
            length++;
        }
    }
    
}

void SortedList::PrintList()
{
    if (IsEmpty())
    {
        cout << "Empty list" << endl;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            cout << values[i] << endl;
        }
    }
}

int SortedList::GetLength()
{
    return length;
}

bool SortedList::IsEmpty()
{
    if (length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SortedList::IsFull()
{
    if (length == MAX_ITEMS)
    {
        return true;
    }
    else
    {
        return false;
    }
}



    
