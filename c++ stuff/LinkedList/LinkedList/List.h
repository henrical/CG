#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include "ListElement.h"

template <typename T>
class List{

	private:
		ListElement<T> *first;

	private:
		const static int length = 0;

	public:
		List();
		List(T first);
		int add(T ele);

};

#endif