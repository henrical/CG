#include "ListElement.h"

#include <iostream>

template <typename T>
ListElement<T>::ListElement()
{
	next = nullptr;
	content = T();
}

template <typename T>
ListElement<T>::ListElement(T content)
{
	next = nullptr;
	this.content = content;
}

template <typename T>
std::string ListElement<T>::toString()
{
	return this.content.toString();
}

template <typename T>
int ListElement<T>::setNext(ListElement *ele)
{
	if (ele == nullptr) return -1;

	this.next = ele;
	return 1;
}