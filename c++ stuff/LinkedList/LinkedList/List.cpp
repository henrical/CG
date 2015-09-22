#include <iostream>

#include "List.h"

template <typename T>
ListElement<T>::ListElement()
{
	next = nullptr;
	content = 0;
}

template <typename T>
ListElement<T>::ListElement(T first)
{
	next = nullptr;
	content = first;
}

template <typename T>
int ListElement<T>::add(T content)
{

	ListElement::length += 1;
}



int main()
{
	ListElement<int>* list = new ListElement<int>();
	std::cout << "fag";
}