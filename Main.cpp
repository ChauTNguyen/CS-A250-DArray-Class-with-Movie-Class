/*
Chau Nguyen
CS A250
April 13, 2016

In-class Exercise 6
*/
//This program creates partially-filled arrays
//  of integers.

#include "DArray.h"
#include "Darray.cpp"
#include "Movie.h"

#include <iostream>
using namespace std;

template <typename T>
bool operator==(DArray<T>& d1, DArray<T>& d2);

int main()
{
	DArray<int> a1;
	cout << "Capacity: " << a1.getCapacity() << endl;
	cout << "Number of elements: " << a1.getUsed() << endl;
	cout << "Empty? " << (a1.isEmpty() ? "True" : "False") << endl;
	cout << "Full? " << (a1.isFull() ? "True" : "False") << endl;
	cout << "Empty the array..." << endl;
	a1.emptyArray();

	cout << endl;

	DArray<int> a2(5);
	a2.addElement(3);
	cout << "Array is: " << a2 << endl;
	cout << "Capacity: " << a2.getCapacity() << endl;
	cout << "Number of elements: " << a2.getUsed() << endl;
	cout << "Empty? " << (a2.isEmpty() ? "True" : "False") << endl;
	cout << "Full? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "Element at idx 0: " << a2[0] << endl;
	cout << "Empty the array..." << endl;
	cout << "Empty? " << (a2.isEmpty() ? "True" : "False") << endl;
	cout << "Re-populate..." << endl;
	a2.emptyArray();
	a2.addElement(21);
	a2.addElement(53);
	a2.addElement(64);
	a2.addElement(19);
	a2.addElement(43);
	cout << "Array is: " << a2 << endl;
	cout << "Capacity: " << a2.getCapacity() << endl;
	cout << "Number of elements: " << a2.getUsed() << endl;
	cout << "Empty? " << (a2.isEmpty() ? "True." : "False") << endl;
	cout << "Full? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "Element at last index: " << a2[a2.getUsed() - 1] << endl;
	cout << "Delete first element..." << endl;
	a2.deleteElement(21);
	cout << "After deletion: " << a2 << endl;
	cout << "Delete last element..." << endl;
	a2.deleteElement(43);
	cout << "Array is: " << a2 << endl;
	cout << "Number of elements: " << a2.getUsed() << endl;
	cout << "Empty? " << (a2.isEmpty() ? "True" : "False") << endl;
	cout << "Full? " << (a2.isFull() ? "True" : "False") << endl;
	cout << "Element at last index: " << a2[a2.getUsed() - 1] << endl;
	cout << "Delete remaining elements..." << endl;
	a2.deleteElement(64);
	a2.deleteElement(53);
	a2.deleteElement(19);
	cout << "Number of elements: " << a2.getUsed() << endl;

	cout << "Add elements again..." << endl;
	a2.addElement(20);
	a2.addElement(21);
	a2.addElement(22);
	cout << "Array is: " << a2 << endl;
	cout << "Copy this array into the first one..." << endl;
	a1 = a2;
	cout << "Other array is: " << a1 << endl;
	cout << "Check if arrays are different..." << endl;
	cout << "Delete first element on first array..." << endl;
	a1.deleteElement(20);
	cout << "Print again..." << endl;
	cout << "First Array is: " << a1 << endl;
	cout << "Array is: " << a2 << endl;

	cout << endl;

	DArray<int> aNew, aAnother;
	aNew.addElement(1);
	aNew.addElement(2);
	aNew.addElement(3);
	aAnother.addElement(40);
	aAnother.addElement(50);
	aAnother.addElement(60);
	cout << "New array: " << aNew << endl;
	cout << "Another array: " << aAnother << endl;
	cout << "Overwrite third element of another array with first element of new array..." << endl;
	aNew[0] = aAnother[2];
	cout << "New array: " << aNew << endl;
	cout << "Another array: " << aAnother << endl;

	cout << "Make new array equal to another array...";
	aNew = aAnother;
	if (aNew.isEmpty()) cout << "aNew is empty." << endl;
	else cout << "aNew is not empty." << endl;

	// Add additional test cases for an object of the DArray class of type Movie
	cout << endl;
	cout << "CREATING DARRAY<MOVIE>" << endl;
	DArray<Movie> movieList;
	movieList.addElement( Movie("Spiderman", 2014) );
	movieList.addElement( Movie("Superbad", 2010) );
	movieList.addElement( Movie() );

	cout << "printing movie list: " << endl << movieList << endl;

	cout << endl;
	
	cout << "Copy constructor test" << endl;
	DArray<int> secondList;

	cout << "Adding elements to secondList" << endl;
	secondList.addElement(0);
	secondList.addElement(1);
	secondList.addElement(3);
	secondList.addElement(99);
	
	cout << "secondList: " << secondList << endl;
	
	cout << "Creating firstList with copy constructor @param: secondList" << endl;
	DArray<int> firstList(secondList);
	cout << "firstList: " << firstList << endl;

	cout << "is firstList equal to secondList? : " << boolalpha << (firstList == secondList) << endl;


	cout << endl;
	system("Pause");
    return 0;
}

template <typename T>
bool operator==(DArray<T>& d1, DArray<T>& d2)
{
	if (d1.getUsed() != d2.getUsed())
		return false;
	else
	{
		int i = 0;
		int numOfElem = d1.getUsed();

		while (i < numOfElem)
		{
			if (d1[i] != d2[i])
				return false;
			i++;
		}

		return true;
	}
}