#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include "ListElement.h"

template <typename T>
class List{

	private:
		ListElement<T> *first;

	private:
		int length;

	public:


		int getLength()
		{
			return length;
		}

		List(){
			first = nullptr;
		}

		List(T first){
			first = new ListElement<T>(content);

		}

		void add(T elem)
		{
			ListElement<T> *newEle;

			if (first == nullptr)
			{
				first = new ListElement<T>(elem);

				List::length = 1;


			}
			else {
				newEle = new ListElement<T>(elem);

				newEle->setNext(first);

				first = newEle;

				List::length += 1;

			}
		}

};

#endif