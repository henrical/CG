#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include "ListElement.h"

template <typename T>
class List{

	private:
		ListElement<T> *first;

	private:
		static int length;

	public:
		static int getLength()
		{
			return length;
		}

		List();
		List(T first);
		int add(T ele);

};

#endif