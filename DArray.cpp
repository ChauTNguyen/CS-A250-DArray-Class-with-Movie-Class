#include "DArray.h"

template<typename T>
ostream& operator<<(ostream& out, const DArray<T>& array)
{
	for (int i = 0; i < array.used; i++)
		out << array.getElement(i) << " ";
	return out;
}

template<typename T>
T& DArray<T>::operator[](int index) const
{
	return a[index];
}

template<typename T>
DArray<T>& DArray<T>::operator=(const DArray<T>& otherArray)
{
	if (&otherArray != this)
	{
		if (capacity != otherArray.capacity)
		{
			delete[] a;
			a = new int[otherArray.capacity];
			capacity = otherArray.capacity;
		}

		for (int i = 0; i < otherArray.used; i++)
			a[i] = otherArray.a[i];

		used = otherArray.used;
	}
	else
		cerr << "Attempted assignment to itself.";

	return *this;
}

template<typename T>
DArray<T>::DArray( )
{
    capacity = 50;
	a = new T[capacity];	
	used = 0;
}

template<typename T>
DArray<T>::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new T[capacity];
	used = 0;	 
}

template<typename T>
DArray<T>::DArray(const DArray& otherArray)
{
	capacity = otherArray.capacity;
	used = otherArray.used;
	a = new int[capacity];
	for (int i = 0; i < used; i++)
		a[i] = otherArray.a[i];
}

template<typename T>
void DArray<T>::addElement(const T& element) 
{
    if (used >= capacity)
    {
        cerr << "Attempt to exceed capacity in DArray.\n";
        exit(0); 
    }
    a[used] = element;
    ++used;
}

template<typename T>
T DArray<T>::getElement(int index) const
{
	return a[index];
}

template<typename T>
void DArray<T>::setElement(int index, const T& newElement)
{
	a[index] = newElement;
}

template<typename T>
void DArray<T>::deleteElement(const T& key)
{
	bool found = false;
	int i = 0;
	while (i < used && !found)
	{
		if (a[i] == key)
			found = true;
		else
			++i;
	}
	if (found)
	{
		while (i < used)
		{
			a[i] = a[i + 1];
			++i;
		}
		--used;
	}
	else
	{
		cout << "Cannot find element " << key << "." << endl;
	}
}

template<typename T>
void DArray<T>::emptyArray()
{
	used = 0;
}

template<typename T>
int DArray<T>::getUsed() const
{
	return used;
}

template<typename T>
int DArray<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
bool DArray<T>::isEmpty() const
{
	return used == 0;
}

template<typename T>
bool DArray<T>::isFull() const
{
	return used == capacity;
}

template<typename T>
DArray<T>::~DArray( )
{
    delete [] a; //delete the array
	a = NULL;	 //null the pointer
}
