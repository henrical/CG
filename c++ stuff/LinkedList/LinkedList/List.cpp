#include <iostream>

#include "List.h"
#include "ListElement.h"

//template <typename T>
//List<T>::List()
//{
//	first = nullptr;
//}
//
//template <typename T>
//List<T>::List(T content)
//{
//	first = new ListElement<T>(content);
//
//}
//
//template <typename T>
//void List<T>::add(T content)
//{
//	ListElement<T> *newEle;
//
//	if(first == nullptr)
//	{
//		first = new ListElement<T>(content);
//
//		List::length = 1;
//		
//		
//	}
//	else {
//		newEle = new ListElement<T>(content);
//
//		newEle->setNext(first);
//
//		first = newEle;
//
//		List::length += 1;
//
//	}
//}
//
//template <typename T>
//int List<T>::getLength(){
//	return length;
//}