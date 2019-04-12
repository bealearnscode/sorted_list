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
    while(!inputFile.eof())
    {
        // while there is a word to be read from the input file
        getline(inputFile, word);
        if(inputFile.eof())
        {
            break;
        }
        // save the word inside the listOfWords object
          listSorted.Insert(word);
    }
    
    // print number of items in the list
    cout << "There are " << listSorted.GetLength() << " items in the list." << endl;
    
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

void SortedList::Insert(string item)
{
    
     if(IsEmpty())
    {
       values[0] = item;
        length++;
    }
    else if (IsFull())
    {
        cout << "Error" << endl;
    }
    else
    {
        int k = length;
        int position = 0;
        while (position < k)
        {
            if (values[position] > item)
            {
                k = position;
                break;
            }
            
            position++;
        }
            for (int i = length; i > position; i--)
            {
                values[i] = values[i - 1];
            }
            values[k] = item;
            length++;
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



    
