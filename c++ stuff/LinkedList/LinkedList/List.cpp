#include <iostream>
#include <string>

#include "List.h"
#include "ListElement.h"

//template <typename T>
//ListElement* List<T>::first = nullptr;

template <typename T>
int List<T>::length = 0;

template <typename T>
List<T>::List()
{
	first = nullptr;
}

template <typename T>
List<T>::List(T content)
{
	first = new ListElement<T>(content);

}

template <typename T>
int List<T>::add(T content)
{
	ListElement<T> *newEle;

	if(first == nullptr)
	{
		first = new ListElement<T>(content);

		List::length = 1;
		
		
	}
	else {
		newEle = new ListElement<T>(content);

		newEle->setNext(first);

		first = newEle;

		List::length += 1;

	}

	return 1;
}



int main()
{
	List<int> lst = List<int>();
	lst.add(3);

}