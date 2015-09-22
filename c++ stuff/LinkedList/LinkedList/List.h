#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>


template <typename T>
class ListElement {

	private:
		ListElement* next;
		T content;

	private:
		const static int length = 0;

	public:
		ListElement();
		ListElement(T first);
		int add(T ele);

};

#endif