#ifndef _LIST_ELEMENT_H_
#define _LIST_ELEMENT_H_

#include <iostream>


template <typename T>
class ListElement{

	private:
		ListElement* next;
		T content;

	public:
		ListElement();
		ListElement(T content);

		std::string toString();

		int setNext(ListElement ele);
};

#endif