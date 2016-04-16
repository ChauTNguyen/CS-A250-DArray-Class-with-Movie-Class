/*
	Chau Nguyen
	CS A250
	April 13, 2016

	In-class Exercise 6
*/

#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>

using namespace std;

template<typename T>
class DArray
{
	template<typename T>
	friend ostream& operator<<(ostream& out, const DArray<T>& array);
public:
    DArray<T>( );
    //Default constructor -	initializes array 
	//						with a capacity of 50.

    DArray<T>(int);
	//Constructor - initializes array with a given capacity.
	//@param int - capacity of the array.


	DArray<T>(const DArray& otherArray);
	/// Copy Constructor

    void addElement(const T& item);
    //addElement - adds an element to the array.
	//@param T& - the element to add to the array.
	
	// accessor function
	T getElement(int index) const;
	// mutator function
	void setElement(int index, const T& newElement);
	// deleteElement
	void deleteElement(const T& key);
	// emptyArray
	void emptyArray();
	// overload assignment operator(=)
	DArray<T>& operator=(const DArray<T>& otherArray);
	// getNumberOfElements
	int getUsed() const;
	// getCapacity
	int getCapacity() const;
	// isEmpty
	bool isEmpty() const;
	// isFull
	bool isFull() const;

	// overload subscript operator[] member function
	T& operator[](int index) const;



	~DArray<T>( ); 
	//Destructor

private:
    T *a;			//will point to an element (it will be an array)
    int capacity;	//capacity of the array
    int used;		//total number of elements in the arrayh
};

#endif