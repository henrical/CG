#include <iostream>

#include "List.h"
#include "ListElement.h"

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

		ListElement::length += 1;
		
		std::cout << "Added element [" << first.toString() << "] at starting position" << std::endl;
	}
	else {
		newEle = new ListElement<T>(content);

		newEle.setNext(first);

		first = newEle;

		List::length += 1;

		/*std::cout*/
	}

}



int main()
{
	List<int> lst = List<int>();
	std::cout << "fag";
}