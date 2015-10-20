#include <iostream>
#include <string>

#include "List.h"
#include "ListElement.h"

int main()
{
	List<int>* list = new List<int>();
	list->add(3);
	list->add(6);
	list->add(0);
}